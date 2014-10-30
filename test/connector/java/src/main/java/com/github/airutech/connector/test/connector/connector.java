
package com.github.airutech.connector.test.connector;

/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

import com.github.airutech.cnetsTransports.nodeRepositoryProtocol.source.*;
import com.github.airutech.cnetsTransports.nodeRepositoryProtocol.msgpack.*;
import com.github.airutech.cnetsTransports.types.*;
import com.github.airutech.cnets.selector.*;
import com.github.airutech.connector.connectionStatusDispatcher.*;
import com.github.airutech.cnetsTransports.nodeRepositoryProtocol.*;
import com.github.airutech.cnets.readerWriter.*;
import com.github.airutech.cnets.runnablesContainer.*;
import com.github.airutech.connector.serializer.*;
import com.github.airutech.cnetsTransports.msgpack.*;
import com.github.airutech.cnets.types.*;
import com.github.airutech.connector.deserializer.*;
import com.github.airutech.connector.test.connector.adapter.*;
import com.github.airutech.cnets.mapBuffer.*;
import com.github.airutech.cnetsTransports.sockjs.*;
public class connector implements RunnableStoppable{
  String[] publishedBuffersNames;String[] subscribedBuffersNames;com.github.airutech.cnetsTransports.types.serializeStreamCallback[] serializersCallbacks;com.github.airutech.cnetsTransports.types.deserializeStreamCallback[] deserializersCallbacks;com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[] outRepoArr;com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[] inRepoArr;com.github.airutech.cnetsTransports.types.connectionStatus[] localConnStatusArr;com.github.airutech.connector.types.localBuffers[] packetOutArr;com.github.airutech.connector.types.localBuffers[] packetInArr;com.github.airutech.cnetsTransports.types.cnetsProtocol[] outCnetsProtocolArr;com.github.airutech.cnetsTransports.types.cnetsProtocol[] inCnetsProtocolArr;String initialConnection;int bindPort;SSLContext sslContext;int countNodesProcessors;int countBuffersProcessors;int maxNodesCount;int buffersLengths;int binBuffersSize;long timeoutInterval;int adapters;int serializers;int deserializers;writer w0;reader r0;reader r1;reader rSelect;selector readersSelector;
  
  public connector(String initialConnection,int bindPort,SSLContext sslContext,int countNodesProcessors,int countBuffersProcessors,int maxNodesCount,int buffersLengths,int binBuffersSize,long timeoutInterval,int adapters,int serializers,int deserializers,writer w0,reader r0,reader r1){
    this.initialConnection = initialConnection;
    this.bindPort = bindPort;
    this.sslContext = sslContext;
    this.countNodesProcessors = countNodesProcessors;
    this.countBuffersProcessors = countBuffersProcessors;
    this.maxNodesCount = maxNodesCount;
    this.buffersLengths = buffersLengths;
    this.binBuffersSize = binBuffersSize;
    this.timeoutInterval = timeoutInterval;
    this.adapters = adapters;
    this.serializers = serializers;
    this.deserializers = deserializers;
    this.w0 = w0;
    this.r0 = r0;
    this.r1 = r1;
    this.publishedBuffersNames = new String[0];
    this.subscribedBuffersNames = new String[1];
    this.serializersCallbacks = new com.github.airutech.cnetsTransports.types.serializeStreamCallback[0];
    this.deserializersCallbacks = new com.github.airutech.cnetsTransports.types.deserializeStreamCallback[1];
    this.outRepoArr = new com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[buffersLengths];
    this.inRepoArr = new com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol[buffersLengths];
    this.localConnStatusArr = new com.github.airutech.cnetsTransports.types.connectionStatus[buffersLengths];
    this.packetOutArr = new com.github.airutech.connector.types.localBuffers[buffersLengths];
    this.packetInArr = new com.github.airutech.connector.types.localBuffers[buffersLengths];
    this.outCnetsProtocolArr = new com.github.airutech.cnetsTransports.types.cnetsProtocol[buffersLengths];
    this.inCnetsProtocolArr = new com.github.airutech.cnetsTransports.types.cnetsProtocol[buffersLengths];
    reader[] arrReaders = new reader[2];
    arrReaders[0] = r0;
    arrReaders[1] = r1;
    this.readersSelector = new selector(arrReaders);
    this.rSelect = readersSelector.getReader(0,-1);
    onCreate();
    initialize();
  }
com.github.airutech.cnets.mapBuffer.mapBuffer _outRepoUpdate;com.github.airutech.cnets.mapBuffer.mapBuffer _inRepoUpdate;com.github.airutech.cnetsTransports.sockjs.sockjs _socket;com.github.airutech.connector.test.connector.adapter.adapter _outAdapter;com.github.airutech.connector.serializer.serializer _serializer;com.github.airutech.connector.deserializer.deserializer _deserializer;com.github.airutech.connector.connectionStatusDispatcher.connectionStatusDispatcher _connStatusDispatcher;com.github.airutech.cnetsTransports.nodeRepositoryProtocol.source.source _repoProtocolSource;com.github.airutech.cnets.mapBuffer.mapBuffer _localConnStatusBuf;com.github.airutech.cnets.mapBuffer.mapBuffer _packetOutBuffers;com.github.airutech.cnets.mapBuffer.mapBuffer _packetInBuffers;com.github.airutech.cnets.mapBuffer.mapBuffer _inCnetsProtocol;com.github.airutech.cnets.mapBuffer.mapBuffer _outCnetsProtocol;
  private void initialize(){
    
    _outRepoUpdate = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])outRepoArr,1000L,1);
    reader _outRepoUpdater0 = _outRepoUpdate.getReader(0);
    writer _outRepoUpdatew0 = _outRepoUpdate.getWriter(0);
    _inRepoUpdate = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])inRepoArr,1000L,3);
    reader _inRepoUpdater0 = _inRepoUpdate.getReader(0);
    reader _inRepoUpdater1 = _inRepoUpdate.getReader(1);
    reader _inRepoUpdater2 = _inRepoUpdate.getReader(2);
    writer _inRepoUpdatew0 = _inRepoUpdate.getWriter(0);
    _localConnStatusBuf = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])localConnStatusArr,1000L,4);
    reader _localConnStatusBufr0 = _localConnStatusBuf.getReader(0);
    reader _localConnStatusBufr1 = _localConnStatusBuf.getReader(1);
    reader _localConnStatusBufr2 = _localConnStatusBuf.getReader(2);
    reader _localConnStatusBufr3 = _localConnStatusBuf.getReader(3);
    writer _localConnStatusBufw0 = _localConnStatusBuf.getWriter(0);
    _packetOutBuffers = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])packetOutArr,1000L,1);
    reader _packetOutBuffersr0 = _packetOutBuffers.getReader(0);
    writer _packetOutBuffersw0 = _packetOutBuffers.getWriter(0);
    _packetInBuffers = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])packetInArr,1000L,1);
    reader _packetInBuffersr0 = _packetInBuffers.getReader(0);
    writer _packetInBuffersw0 = _packetInBuffers.getWriter(0);
    _inCnetsProtocol = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])inCnetsProtocolArr,1000L,1);
    reader _inCnetsProtocolr0 = _inCnetsProtocol.getReader(0);
    writer _inCnetsProtocolw0 = _inCnetsProtocol.getWriter(0);
    _outCnetsProtocol = new com.github.airutech.cnets.mapBuffer.mapBuffer((Object[])outCnetsProtocolArr,1000L,1);
    reader _outCnetsProtocolr0 = _outCnetsProtocol.getReader(0);
    writer _outCnetsProtocolw0 = _outCnetsProtocol.getWriter(0);
    onKernels();
    
    _socket = new com.github.airutech.cnetsTransports.sockjs.sockjs((string[])publishedBuffersNames,(int)maxNodesCount,(String)initialConnection,(int)bindPort,(SSLContext)sslContext,_localConnStatusBufw0,_inCnetsProtocolw0,_outCnetsProtocolr0,this.r0,_inRepoUpdater0);
    _outAdapter = new com.github.airutech.connector.test.connector.adapter.adapter((string[])publishedBuffersNames,(string[])subscribedBuffersNames,(serializeStreamCallback[])serializersCallbacks,(deserializeStreamCallback[])deserializersCallbacks,_inRepoUpdatew0,_packetOutBuffersw0,_outRepoUpdater0,_packetInBuffersr0,this.r1);
    _serializer = new com.github.airutech.connector.serializer.serializer((string[])publishedBuffersNames,(int)maxNodesCount,_outCnetsProtocolw0,_localConnStatusBufr2,_inRepoUpdater1,_packetOutBuffersr0);
    _deserializer = new com.github.airutech.connector.deserializer.deserializer((string[])subscribedBuffersNames,(int)maxNodesCount,_packetInBuffersw0,_localConnStatusBufr3,_inRepoUpdater2,_inCnetsProtocolr0);
    _connStatusDispatcher = new com.github.airutech.connector.connectionStatusDispatcher.connectionStatusDispatcher(this.w0,_localConnStatusBufr1);
    _repoProtocolSource = new com.github.airutech.cnetsTransports.nodeRepositoryProtocol.source.source((string[])publishedBuffersNames,(string[])subscribedBuffersNames,_outRepoUpdatew0,_localConnStatusBufr0);
  }
  public runnablesContainer getRunnables(){
    
    runnablesContainer runnables = new runnablesContainer();
    runnablesContainer[] arrContainers = new runnablesContainer[6];
    arrContainers[0] = _socket.getRunnables();
    arrContainers[1] = _outAdapter.getRunnables();
    arrContainers[2] = _serializer.getRunnables();
    arrContainers[3] = _deserializer.getRunnables();
    arrContainers[4] = _connStatusDispatcher.getRunnables();
    arrContainers[5] = _repoProtocolSource.getRunnables();

    runnables.setContainers(arrContainers);
    return runnables;
  }
/*[[[end]]] (checksum: 141707a1539441211ea9173b9801304d)*/

  private void onCreate(){

  }

  private void onKernels(){

  }

  @Override
  public void onStart(){

  }

  @Override
  public void run(){
    
    _socket.run();
    _outAdapter.run();
    _serializer.run();
    _deserializer.run();
    _connStatusDispatcher.run();
    _repoProtocolSource.run();
  }

  @Override
  public void onStop(){

  }

}

