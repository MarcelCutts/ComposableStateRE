type state = {counter: int};

type action =
  | IncrementOn(int)
  | DecrementOn(int);

let component = ReasonReact.reducerComponent("CounterReducer");
let make = _children => {
  ...component,
  initialState: () => {counter: 0},
  reducer: (action, state) =>
    switch (action) {
    | IncrementOn(amount) =>
      ReasonReact.Update({counter: state.counter + amount})
    | DecrementOn(amount) =>
      ReasonReact.Update({counter: state.counter - amount})
    },
  render: self =>
    <div>
      ("Count: " ++ string_of_int(self.state.counter) |> ReasonReact.string)
      <button onClick=(_event => self.send(IncrementOn(2)))>
        ("Inc" |> ReasonReact.string)
      </button>
      <button onClick=(_event => self.send(DecrementOn(3)))>
        ("Dec" |> ReasonReact.string)
      </button>
    </div>,
};