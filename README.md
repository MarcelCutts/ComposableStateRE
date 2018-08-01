# ReasonML Composable Component State

This project explores different way of composing state onto components within ReasonML.

#### Approaches

1.  Reducer component focused on a counter
1.  withState Higher-Order-Component (HOC) bound to [Recompose's withState](https://github.com/acdlite/recompose/blob/master/docs/API.md#withstate)
1.  withState HOC in generic pure ReasonML
1.  Render prop generic component in pure ReasonML

See the [result here](https://marcelcutts.github.io/ComposableStateRE/).

## Run Project

```sh
yarn
yarn start
# in another tab
yarn webpack
```

After you see the webpack compilation succeed (the `npm run webpack` step), open up `src/index.html` (**no server needed!**). Then modify whichever `.re` file in `src` and refresh the page to see the changes.

**For more elaborate ReasonReact examples**, please see https://github.com/reasonml-community/reason-react-example

## Build for Production

```sh
yarn build
yarn webpack:production
```

This will replace the development artifact `build/Index.js` for an optimized version.

**To enable dead code elimination**, change `bsconfig.json`'s `package-specs` `module` from `"commonjs"` to `"es6"`. Then re-run the above 2 commands. This will allow Webpack to remove unused code.
