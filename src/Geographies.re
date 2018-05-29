[@bs.module "react-simple-maps"]
external geographies: ReasonReact.reactClass = "Geographies";

[@bs.deriving abstract]
type geographiesProps = {
  geography: string,
};

type geographies = array(Geography.geographyT);

let make = (
  ~geography,
  children: geographies => Geography.projectionT => ReasonReact.reactElement,
) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographies,
    ~props=geographiesProps(
      ~geography
    ),
    children
  );