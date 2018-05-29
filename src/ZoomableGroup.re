[@bs.module "react-simple-maps"]
external zoomableGroup: ReasonReact.reactClass = "ZoomableGroup";

[@bs.deriving abstract]
type zoomableProps = {
  center: array(int),
};

let make = (~center, children) => 
  ReasonReact.wrapJsForReason(
    ~reactClass=zoomableGroup,
    ~props=zoomableProps(
      ~center
    ),
    children,
  );