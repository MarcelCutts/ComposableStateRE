type hoc = ReasonReact.reactClass => ReasonReact.reactClass;

module type CreateWithStateParams = {type state; let defaultValue: state;};

module CreateWithState = (Params: CreateWithStateParams) => {
  [@bs.module "recompose"]
  external withState : (string, string, Params.state) => hoc = "withState";
  type setState = (. Params.state) => unit;

  type children =
    (~setState: setState, ~state: Params.state) => ReasonReact.reactElement;
  let component = ReasonReact.statelessComponent("WithState");
  let make' = (~setState: setState, ~state: Params.state, children: children) => {
    ...component,
    render: _self => children(~setState, ~state),
  };

  let jsComponent =
    ReasonReact.wrapReasonForJs(
      ~component,
      (
        props: {
          .
          "setState": setState,
          "state": Params.state,
          "children": children,
        },
      ) =>
      make'(~setState=props##setState, ~state=props##state, props##children)
    );
  let enhanced =
    withState("state", "setState", Params.defaultValue, jsComponent);
  let make = (children: children) =>
    ReasonReact.wrapJsForReason(
      ~reactClass=enhanced,
      ~props=Js.Obj.empty(),
      children,
    );
};

module WithCountState =
  CreateWithState({
    type state = int;
    let defaultValue = 0;
  });

let component = ReasonReact.statelessComponent("WithStateRecompose");
let make = _children => {
  ...component,
  render: _self =>
    <WithCountState>
      ...(
           (~setState, ~state as count) =>
             <div>
               ("Count: " ++ string_of_int(count) |> ReasonReact.string)
               <button onClick=(_ => setState(. count + 2))>
                 ("Inc" |> ReasonReact.string)
               </button>
               <button onClick=(_ => setState(. count - 3))>
                 ("Dec" |> ReasonReact.string)
               </button>
             </div>
         )
    </WithCountState>,
};