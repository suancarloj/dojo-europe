[@bs.module "react-simple-maps"]
external geographyClass: ReasonReact.reactClass = "Geography";

type geographyT = {
  id: int,  
};

type projectionT;

type styleObj = {
  fill: string,
  stroke: string,
  strokeWidth: float,
  outline: string,
};

type styleT = {
  default: styleObj,
  hover: styleObj,
  pressed: styleObj,
};


[@bs.deriving abstract]
type geographyProps = {
  geography: geographyT,
  projection: projectionT,
  style: styleT,
};

let make = (
  ~geography,
  ~projection,
  ~style,
  children,
) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=geographyClass,
    ~props=geographyProps(
      ~geography,
      ~projection,
      ~style,
    ),
    children,
  );