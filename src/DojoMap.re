let component = ReasonReact.statelessComponent("DojoMap");

let str = ReasonReact.stringToElement;

let marker = Marker.markerT(~markerOffset=-25, ~name="Brussels", ~coordinates=[| 4.357888, 50.833456 |]);

let make = _children => {
  ...component,
  didMount: _self => {
    Fetcher.fetchPost("https://immense-river-25513.herokuapp.com/add-location", "suancarloj");
  },
  render: _self =>
    <div style=(ReactDOMRe.Style.make(~width="100%", ~maxWidth="980px", ~margin="0 auto", ()))>
      <ComposableMap
        projectionConfig={scale: 800}
        width=1000
        height=1000
        style=(ReactDOMRe.Style.make(~width="100%", ~height="auto", ~margin="0 auto", ()))>

          <ZoomableGroup center=[|(0), (20)|]>
            <Geographies geography="/world-50m.json">
              ...(
                  (geographies, projection) => {
                    ReasonReact.array(
                        Array.mapi(
                          (i, geography) => {
                             <Geography
                               key=(string_of_int(i))
                               geography
                               projection
                               style={
                                 default: {
                                   fill: "#ECEFF1",
                                   stroke: "#607D8B",
                                   strokeWidth: 0.75,
                                   outline: "none",
                                 },
                                 hover: {
                                   fill: "#CFD8DC",
                                   stroke: "#607D8B",
                                   strokeWidth: 0.75,
                                   outline: "none",
                                 },
                                 pressed: {
                                   fill: "#FF5722",
                                   stroke: "#607D8B",
                                   strokeWidth: 0.75,
                                   outline: "none",
                                 },
                               }
                             />
                              },
                              geographies
                         ),
                     )
                  }
                 )
            </Geographies>
            <Markers>
              <Marker
                marker=marker
                style={{
                  default: ReactDOMRe.Style.make(~fill="#FF5722", ()),
                  hover: ReactDOMRe.Style.make(~fill="#FFFFFF", ()),
                  pressed: ReactDOMRe.Style.make(~fill="#FF5722", ()),
                }}
              >
                <circle
                  cx="0"
                  cy="0"
                  r="10"
                  style=(ReactDOMRe.Style.make(~stroke="#FF5722", ~strokeWidth="3", ~opacity="0.9", ()))
                />
                <text
                  textAnchor="middle"
                  y="-25"
                  style=(ReactDOMRe.Style.make(~fontFamily="Roboto, sans-serif", ~fill="#607D8B", ()))
                >
                  {ReasonReact.string("Brussels")}
                </text>
              </Marker>
            </Markers>
          </ZoomableGroup>
        </ComposableMap>
    </div>
};