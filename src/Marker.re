[@bs.module "react-simple-maps"]
external markerClass: ReasonReact.reactClass = "Marker";

[@bs.deriving abstract]
type markerT = {
  name: string,
  coordinates: array(float),
  markerOffset: int,
};

type style = {
  default: ReactDOMRe.Style.t,
  hover: ReactDOMRe.Style.t,
  pressed: ReactDOMRe.Style.t,
};


[@bs.deriving abstract]
type markerProps = {
  marker: markerT,
  style: style,
};

let make = (
  ~marker,
  ~style,
  children,
) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=markerClass,
    ~props=markerProps(
      ~marker,
      ~style,
    ),
    children,
  );