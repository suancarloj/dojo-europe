[@bs.module "react-simple-maps"]
external composableMap: ReasonReact.reactClass = "ComposableMap";

type composableMapProjectionConfigProps = {
  scale: int,
  /* rotation: Js.nullable(list(int)), */
};

[@bs.deriving abstract]
type composableMapProps = {
  projectionConfig: composableMapProjectionConfigProps,
  width: int,
  height: int,
  style: ReactDOMRe.Style.t,
};

let make = (
  ~projectionConfig,
  ~width,
  ~height,
  ~style,
  children,
) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=composableMap,
    ~props=composableMapProps(
      ~projectionConfig,
      ~width,
      ~height,
      ~style,
    ),
    children,
  );