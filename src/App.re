let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self =>
    <div>
      <h3> ("Reducer component only" |> ReasonReact.string) </h3>
      <CounterReducer />
      <hr />
      <h3> ("WithState from Recompose" |> ReasonReact.string) </h3>
      <WithStateRecompose />
      <hr />
      <h3> ("WithState ReasonML" |> ReasonReact.string) </h3>
      <WithState />
      <hr />
      <h3> ("RenderProp ReasonML" |> ReasonReact.string) </h3>
      <StateRenderProp.Counter />
    </div>,
};