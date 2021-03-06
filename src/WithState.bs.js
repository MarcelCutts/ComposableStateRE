// Generated by BUCKLESCRIPT VERSION 4.0.2, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");
var Curry = require("bs-platform/lib/js/curry.js");
var React = require("react");
var ReasonReact = require("reason-react/src/ReasonReact.js");

function CreateWithState() {
  var component = ReasonReact.reducerComponent("WithState");
  var make = function (defaultValue, children) {
    return /* record */[
            /* debugName */component[/* debugName */0],
            /* reactClassInternal */component[/* reactClassInternal */1],
            /* handedOffState */component[/* handedOffState */2],
            /* willReceiveProps */component[/* willReceiveProps */3],
            /* didMount */component[/* didMount */4],
            /* didUpdate */component[/* didUpdate */5],
            /* willUnmount */component[/* willUnmount */6],
            /* willUpdate */component[/* willUpdate */7],
            /* shouldUpdate */component[/* shouldUpdate */8],
            /* render */(function (self) {
                var setState = function (value) {
                  return Curry._1(self[/* send */3], /* UpdateValue */[value]);
                };
                return Curry._2(children, setState, self[/* state */1][/* value */0]);
              }),
            /* initialState */(function () {
                return /* record */[/* value */defaultValue];
              }),
            /* retainedProps */component[/* retainedProps */11],
            /* reducer */(function (action, _) {
                return /* Update */Block.__(0, [/* record */[/* value */action[0]]]);
              }),
            /* subscriptions */component[/* subscriptions */13],
            /* jsElementWrapped */component[/* jsElementWrapped */14]
          ];
  };
  return /* module */[
          /* component */component,
          /* make */make
        ];
}

var component = ReasonReact.reducerComponent("WithState");

function make(defaultValue, children) {
  return /* record */[
          /* debugName */component[/* debugName */0],
          /* reactClassInternal */component[/* reactClassInternal */1],
          /* handedOffState */component[/* handedOffState */2],
          /* willReceiveProps */component[/* willReceiveProps */3],
          /* didMount */component[/* didMount */4],
          /* didUpdate */component[/* didUpdate */5],
          /* willUnmount */component[/* willUnmount */6],
          /* willUpdate */component[/* willUpdate */7],
          /* shouldUpdate */component[/* shouldUpdate */8],
          /* render */(function (self) {
              var setState = function (value) {
                return Curry._1(self[/* send */3], /* UpdateValue */[value]);
              };
              return Curry._2(children, setState, self[/* state */1][/* value */0]);
            }),
          /* initialState */(function () {
              return /* record */[/* value */defaultValue];
            }),
          /* retainedProps */component[/* retainedProps */11],
          /* reducer */(function (action, _) {
              return /* Update */Block.__(0, [/* record */[/* value */action[0]]]);
            }),
          /* subscriptions */component[/* subscriptions */13],
          /* jsElementWrapped */component[/* jsElementWrapped */14]
        ];
}

var WithCountState = /* module */[
  /* component */component,
  /* make */make
];

var component$1 = ReasonReact.statelessComponent("WithState");

function make$1() {
  return /* record */[
          /* debugName */component$1[/* debugName */0],
          /* reactClassInternal */component$1[/* reactClassInternal */1],
          /* handedOffState */component$1[/* handedOffState */2],
          /* willReceiveProps */component$1[/* willReceiveProps */3],
          /* didMount */component$1[/* didMount */4],
          /* didUpdate */component$1[/* didUpdate */5],
          /* willUnmount */component$1[/* willUnmount */6],
          /* willUpdate */component$1[/* willUpdate */7],
          /* shouldUpdate */component$1[/* shouldUpdate */8],
          /* render */(function () {
              return ReasonReact.element(undefined, undefined, make(0, (function (setState, state) {
                                return React.createElement("div", undefined, "Count: " + String(state), React.createElement("button", {
                                                onClick: (function () {
                                                    return Curry._1(setState, state + 2 | 0);
                                                  })
                                              }, "Inc"), React.createElement("button", {
                                                onClick: (function () {
                                                    return Curry._1(setState, state - 3 | 0);
                                                  })
                                              }, "Dec"));
                              })));
            }),
          /* initialState */component$1[/* initialState */10],
          /* retainedProps */component$1[/* retainedProps */11],
          /* reducer */component$1[/* reducer */12],
          /* subscriptions */component$1[/* subscriptions */13],
          /* jsElementWrapped */component$1[/* jsElementWrapped */14]
        ];
}

exports.CreateWithState = CreateWithState;
exports.WithCountState = WithCountState;
exports.component = component$1;
exports.make = make$1;
/* component Not a pure module */
