<%import parsing_connector, json
p = reload(parsing_connector)
p.parsingGernet(a)
%>
,
"type":"com.github.airutech.gernet.plugins.kernel",
"props": [{
  "name": "publishedBuffersNames",
  "type": "string[]",
  "size": ${p.publishedBuffersCount(a)}
},{
  "name": "subscribedBuffersNames",
  "type": "string[]",
  "size": ${p.subscribedBuffersCount(a)}
},{
  "name": "serializersCallbacks",
  "type": "com.github.airutech.cnetsTransports.types.serializeStreamCallback[]",
  "size": ${p.publishedBuffersCount(a)}
},{
  "name": "deserializersCallbacks",
  "type": "com.github.airutech.cnetsTransports.types.deserializeStreamCallback[]",
  "size": ${p.subscribedBuffersCount(a)}
},{
  "name": "outRepoArr",
  "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[]",
  "size": "buffersLengths"
},{
  "name": "inRepoArr",
  "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[]",
  "size": "buffersLengths"
},{
  "name": "localConnStatusArr",
  "type": "com.github.airutech.cnetsTransports.types.connectionStatus[]",
  "size": "buffersLengths"
},{
  "name": "packetOutArr",
  "type": "com.github.airutech.connector.types.localBuffers[]",
  "size": "buffersLengths"
},{
  "name": "packetInArr",
  "type": "com.github.airutech.connector.types.localBuffers[]",
  "size": "buffersLengths"
},{
  "name": "outCnetsProtocolArr",
  "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol[]",
  "size": "buffersLengths"
},{
  "name": "inCnetsProtocolArr",
  "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol[]",
  "size": "buffersLengths"
}],
"args": [{
  "name": "initialConnection",
  "type": "String",
  "value": ""
},{
  "name": "bindPort",
  "type": "int",
  "value": 9911
},{
  "name": "sslContext",
  "type": "SSLContext",
  "value": "null"
},{
  "name": "countNodesProcessors",
  "type": "int",
  "value": 2
},{
  "name": "countBuffersProcessors",
  "type": "int",
  "value": 2
},{
  "name": "maxNodesCount",
  "type": "int",
  "value": 5
},{
  "name": "buffersLengths",
  "type": "int",
  "value": 8
},{
  "name": "binBuffersSize",
  "type": "int",
  "value": 128
},{
  "name": "timeoutInterval",
  "type": "long",
  "value": "1000L"
},{
  "name": "adapters",
  "type": "int",
  "value": 10
},{
  "name": "serializers",
  "type": "int",
  "value": 10
},{
  "name": "deserializers",
  "type": "int",
  "value": 10
}],
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
  "path":"com.github.airutech.cnetsTransports.types",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnets.types",
  "ver": "[0.0.0,)"
},{
  "path":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol",
  "ver": "[0.0.0,)"
},{
  "path":"${p.nodeRepositoryProtocolSerializerPath(a)}",
  "ver": "[0.0.0,)"
},{
  "path":"${p.serializerPath(a)}",
  "ver": "[0.0.0,)"
}],
"blocks": [{
  "id":0,
  "type":"buffer",
  "name":"_outRepoUpdate",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"outRepoArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 1
  }],
  "connection": {
    "writeTo": [{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "blockId": 3,
      "pinId": 0
    }],
    "readFrom": [{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    }]
  }
},{
  "id":1,
  "type":"buffer",
  "name": "_inRepoUpdate",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"inRepoArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 3
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "blockId": 2,
      "pinId": 2
    },{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "blockId": 4,
      "pinId": 1
    },{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "blockId": 5,
      "pinId": 1
    }],
    "readFrom": [{
      "type": "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "description": "this reader should be taken from the deserializer"
    }]
  }
},{
  "id":2,
  "name": "_socket",
  "path":"${p.socketPath(a)}",
  "ver":"[0.0.0,)",
  "args": [{
    "name": "publishedBuffersNames",
    "type": "string[]",
    "value": "publishedBuffersNames"
  },{
    "name": "maxNodesCount",
    "type": "int",
    "value": "maxNodesCount"
  },{
    "name": "initialConnection",
    "type": "String",
    "value": "initialConnection"
  },{
    "name": "bindPort",
    "type": "int",
    "value": "bindPort"
  },{
    "name": "sslContext",
    "type": "SSLContext",
    "value": "sslContext"
  }],
  "connection":{
    "writeTo": [{
      "name":"statuses",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId": 8,
      "pinId": 0
    },{
      "name":"fromSocket",
      "type":"com.github.airutech.cnetsTransports.types.cnetsProtocol",
      "blockId": 11,
      "pinId": 0
    }],
    "readFrom": [{
      "name":"toSocket",
      "type":"com.github.airutech.cnetsTransports.types.cnetsProtocol"
    },{
      "name":"connections",
      "type":"com.github.airutech.cnetsTransports.types.cnetsConnections",
      "blockId": "export",
      "pinId": 0
    },{
      "name":"receiveRemoteRepository",
      "type":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    }]
  }
},{
  "id":3,
  "parallel": "adapters",
  "name": "_outAdapter",
  "path":"${a.domainName}.${a.className}.connector.adapter",
  "ver":"[0.0.0,)",
  "args": [{
    "name": "publishedBuffersNames",
    "type": "string[]",
    "value": "publishedBuffersNames"
  },{
    "name": "subscribedBuffersNames",
    "type": "string[]",
    "value": "subscribedBuffersNames"
  },{
    "name": "serializersCallbacks",
    "type": "serializeStreamCallback[]",
    "value": "serializersCallbacks"
  },{
    "name": "deserializersCallbacks",
    "type": "deserializeStreamCallback[]",
    "value": "deserializersCallbacks"
  }],
  "connection":${p.adapterConnections(a)}
},{
  "id":4,
  "parallel": "serializers",
  "name": "_serializer",
  "path":"com.github.airutech.connector.serializer",
  "ver":"[0.0.0,)",
  "args": [{
    "name": "publishedBuffersNames",
    "type": "string[]",
    "value": "publishedBuffersNames"
  },{
    "name": "maxNodesCount",
    "type": "int",
    "value": "maxNodesCount"
  }],
  "connection":{
    "writeTo": [{
      "name":"output",
      "type":"com.github.airutech.cnetsTransports.types.cnetsProtocol",
      "blockId": 12,
      "pinId": 0
    }],
    "readFrom": [{
      "name":"connectionStatus",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus"
    },{
      "name":"receiveRemoteRepository",
      "type":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    },{
      "name":"localBuffers",
      "type":"com.github.airutech.connector.types.localBuffers"
    }]
  }
},{
  "id":5,
  "parallel": "deserializers",
  "name": "_deserializer",
  "path":"com.github.airutech.connector.deserializer",
  "ver":"[0.0.0,)",
  "args": [{
    "name": "subscribedBuffersNames",
    "type": "string[]",
    "value": "subscribedBuffersNames"
  },{
    "name": "maxNodesCount",
    "type": "int",
    "value": "maxNodesCount"
  }],
  "connection":{
    "writeTo": [{
      "name":"localBuffers",
      "type":"com.github.airutech.connector.types.localBuffers",
      "blockId": 10,
      "pinId": 0
    }],
    "readFrom": [{
      "name":"connectionStatus",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus"
    },{
      "name":"receiveRemoteRepository",
      "type":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    },{
      "name":"input",
      "type":"com.github.airutech.cnetsTransports.types.cnetsProtocol"
    }]
  }
},{
  "id":6,
  "name": "_connStatusDispatcher",
  "path":"com.github.airutech.connector.connectionStatusDispatcher",
  "ver":"[0.0.0,)",
  "args": [],
  "connection":{
    "writeTo": [{
      "name":"publishExternally",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId":"export",
      "pinId":0
    }],
    "readFrom": [{
      "name":"inputStatus",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus"
    }]
  }
},{
  "id":7,
  "name": "_repoProtocolSource",
  "path":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol.source",
  "ver":"[0.0.0,)",
  "args": [{
    "name": "publishedBuffersNames",
    "type": "string[]",
    "value": "publishedBuffersNames"
  },{
    "name": "subscribedBuffersNames",
    "type": "string[]",
    "value": "subscribedBuffersNames"
  }],
  "connection":{
    "writeTo": [{
      "name":"sendRepositoryToDestination",
      "type":"com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol",
      "blockId": 0,
      "pinId": 0
    }],
    "readFrom": [{
      "name":"connectionStatus",
      "type":"com.github.airutech.cnetsTransports.types.connectionStatus"
    }]
  }
},{
  "id":8,
  "type":"buffer",
  "name": "_localConnStatusBuf",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"localConnStatusArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 4
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId": 7,
      "pinId": 0
    },{
      "type": "com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId": 6,
      "pinId": 0
    },{
      "type": "com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId": 4,
      "pinId": 0
    },{
      "type": "com.github.airutech.cnetsTransports.types.connectionStatus",
      "blockId": 5,
      "pinId": 0
    }],
    "readFrom": [{
      "type": "com.github.airutech.cnetsTransports.types.connectionStatus"
    }]
  }
},{
  "id":9,
  "type":"buffer",
  "name": "_packetOutBuffers",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"packetOutArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 1
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.connector.types.localBuffers",
      "blockId": 4,
      "pinId": 2
    }],
    "readFrom": [{
      "type": "com.github.airutech.connector.types.localBuffers"
    }]
  }
},{
  "id":10,
  "type":"buffer",
  "name": "_packetInBuffers",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"packetInArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 1
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.connector.types.localBuffers",
      "blockId": 3,
      "pinId": 1
    }],
    "readFrom": [{
      "type": "com.github.airutech.connector.types.localBuffers"
    }]
  }
},{
  "id":11,
  "type":"buffer",
  "name": "_inCnetsProtocol",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"inCnetsProtocolArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 1
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol",
      "blockId": 5,
      "pinId": 2
    }],
    "readFrom": [{
      "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol"
    }]
  }
},{
  "id":12,
  "type":"buffer",
  "name": "_outCnetsProtocol",
  "path":"com.github.airutech.cnets.mapBuffer",
  "ver":"[0.0.0,)",
  "args": [{
    "name":"buffers",
    "value":"outCnetsProtocolArr",
    "type":"Object[]"
  },{
    "name": "timeout_milisec",
    "value": "1000L"
  },{
    "name": "readers_grid_size",
    "value": 1
  }],
  "connection":{
    "writeTo": [{
      "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol",
      "blockId": 2,
      "pinId": 0
    }],
    "readFrom": [{
      "type": "com.github.airutech.cnetsTransports.types.cnetsProtocol"
    }]
  }
}
]
