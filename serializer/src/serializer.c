/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../serializer.h"
#include <stdlib.h>

void serializer_connector_osblinnikov_github_com_run(void *that);
void serializer_connector_osblinnikov_github_com_onStart(void *that);
void serializer_connector_osblinnikov_github_com_onStop(void *that);
void serializer_connector_osblinnikov_github_com_onCreate(struct serializer_connector_osblinnikov_github_com *that);
void serializer_connector_osblinnikov_github_com_onDestroy(struct serializer_connector_osblinnikov_github_com *that);
void serializer_connector_osblinnikov_github_com_onKernels(struct serializer_connector_osblinnikov_github_com *that);
struct arrayObject serializer_connector_osblinnikov_github_com_getReaders(void *t);
void serializer_connector_osblinnikov_github_com_setReadData(void *t, bufferReadData *readData);

struct runnablesContainer_cnets_osblinnikov_github_com serializer_connector_osblinnikov_github_com_getRunnables(struct serializer_connector_osblinnikov_github_com *that){
  return that->_runnables;
}

struct arrayObject serializer_connector_osblinnikov_github_com_getReaders(void *t){
  struct serializer_connector_osblinnikov_github_com *that = (struct serializer_connector_osblinnikov_github_com*)t;
  return that->_arrReaders_;
}


void serializer_connector_osblinnikov_github_com_setReadData(void *t, bufferReadData *readData){
  if(t == NULL || readData == NULL){return;}
  struct serializer_connector_osblinnikov_github_com *that = (struct serializer_connector_osblinnikov_github_com*)t;
  
  that->rSelect.setReadData(&that->rSelect,readData);
}


void serializer_connector_osblinnikov_github_com_init(struct serializer_connector_osblinnikov_github_com *that,
    arrayObject _publishedBuffersNames,
    int32_t _maxNodesCount,
    writer _woutput0,
    reader _rconnectionStatus0,
    reader _rreceiveRemoteRepository1,
    reader _rlocalBuffers2){
  
  that->publishedBuffersNames = _publishedBuffersNames;
  that->maxNodesCount = _maxNodesCount;
  that->_arrReaders_ = arrayObject_init_dynamic(sizeof(reader), 3);
  ((reader*)that->_arrReaders_.array)[0] = _rconnectionStatus0;
  ((reader*)that->_arrReaders_.array)[1] = _rreceiveRemoteRepository1;
  ((reader*)that->_arrReaders_.array)[2] = _rlocalBuffers2;
  selector_cnets_osblinnikov_github_com_init(&that->readersSelector, that->_arrReaders_);
  that->rSelect = selector_cnets_osblinnikov_github_com_createReader(&that->readersSelector, 0);
  that->woutput0 = _woutput0;
  that->rconnectionStatus0 = _rconnectionStatus0;
  that->rreceiveRemoteRepository1 = _rreceiveRemoteRepository1;
  that->rlocalBuffers2 = _rlocalBuffers2;
  
  serializer_connector_osblinnikov_github_com_onKernels(that);
  
  that->getRunnables = serializer_connector_osblinnikov_github_com_getRunnables;
  
    runnablesContainer_cnets_osblinnikov_github_com_init(&that->_runnables);
    RunnableStoppable_create(runnableStoppableObj,that, serializer_connector_osblinnikov_github_com)
    that->_runnables.setCore(&that->_runnables,runnableStoppableObj, 0);
  serializer_connector_osblinnikov_github_com_onCreate(that);
}

void serializer_connector_osblinnikov_github_com_deinit(struct serializer_connector_osblinnikov_github_com *that){
  serializer_connector_osblinnikov_github_com_onDestroy(that);
  
  arrayObject_free_dynamic(that->readersSelector.reducableReaders);
  selector_cnets_osblinnikov_github_com_deinit(&that->readersSelector);
}

/*[[[end]]] (checksum: 3b046e120584719e8d72d576bbdb21cc)*/

void serializer_connector_osblinnikov_github_com_run(void *t){
  /*struct serializer_connector_osblinnikov_github_com *that = (struct serializer_connector_osblinnikov_github_com*)t;*/
}

void serializer_connector_osblinnikov_github_com_onStart(void *t){
  /*struct serializer_connector_osblinnikov_github_com *that = (struct serializer_connector_osblinnikov_github_com*)t;*/
}

void serializer_connector_osblinnikov_github_com_onStop(void *t){
  /*struct serializer_connector_osblinnikov_github_com *that = (struct serializer_connector_osblinnikov_github_com*)t;*/
}

void serializer_connector_osblinnikov_github_com_onCreate(struct serializer_connector_osblinnikov_github_com *that){
  
  return;
}

void serializer_connector_osblinnikov_github_com_onDestroy(struct serializer_connector_osblinnikov_github_com *that){
  
  return;
}

void serializer_connector_osblinnikov_github_com_onKernels(struct serializer_connector_osblinnikov_github_com *that){
  
  return;
}
