module StateComponent = (Config: {type data;}) => {
  type value;
  type state = Config.data;

  type action =
    | UpdateValue(Config.data);

  let component = ReasonReact.reducerComponent("WithState");

  let make = (~defaultValue: Config.data, ~render, _children) => {
    ...component,
    initialState: () => defaultValue,
    reducer: (action, _state) =>
      switch (action) {
      | UpdateValue(value) => ReasonReact.Update(value)
      },
    render: self => render(self.state, self.send),
  };
};

module CounterState =
  StateComponent({
    type data = int;
  });

module Counter = {
  let make = _children =>
    CounterState.make(
      ~defaultValue=0,
      ~render=
        (state, send) =>
          <div>
            ("Count: " ++ string_of_int(state) |> ReasonReact.string)
            <button onClick=(_ => send(UpdateValue(state + 2)))>
              ("Inc" |> ReasonReact.string)
            </button>
            <button onClick=(_ => send(UpdateValue(state - 3)))>
              ("Dec" |> ReasonReact.string)
            </button>
          </div>,
      [||],
    );
};