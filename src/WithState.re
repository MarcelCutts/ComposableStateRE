module type CreateWithStateParams = {type state;};

module CreateWithState = (Params: CreateWithStateParams) => {
  type value;
  type state = {value: Params.state};

  type action =
    | UpdateValue(Params.state);

  let component = ReasonReact.reducerComponent("WithState");

  let make = (~defaultValue: Params.state, children) => {
    ...component,
    initialState: () => {value: defaultValue},
    reducer: (action, _state) =>
      switch (action) {
      | UpdateValue(value) => ReasonReact.Update({value: value})
      },
    render: self => {
      let setState = value => self.send(UpdateValue(value));
      children(~setState, ~state=self.state.value);
    },
  };
};

module WithCountState =
  CreateWithState({
    type state = int;
  });

let component = ReasonReact.statelessComponent("WithState");
let make = _children => {
  ...component,
  render: _self =>
    <WithCountState defaultValue=0>
      ...(
           (~setState, ~state) =>
             <div>
               ("Count: " ++ string_of_int(state) |> ReasonReact.string)
               <button onClick=(_ => setState(state + 2))>
                 ("Inc" |> ReasonReact.string)
               </button>
               <button onClick=(_ => setState(state - 3))>
                 ("Dec" |> ReasonReact.string)
               </button>
             </div>
         )
    </WithCountState>,
};