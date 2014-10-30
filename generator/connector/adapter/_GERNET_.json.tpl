<%import parsing_connector, json
p = reload(parsing_connector)
p.parsingGernet(a)%>
,
"props": [],
"depends":[{
  "path":"com.github.airutech.cnets.readerWriter",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnets.runnablesContainer",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnets.selector",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnets.types",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnetsTransports.types",
  "ver": "[0.0.0,)"
}],
"blocks": [],
"connection":${p.getConnections(a)}