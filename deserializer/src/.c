/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../.h"
#include <stdlib.h>

void __run(void *that);
void __onStart(void *that);
void __onStop(void *that);
void __onCreate(struct _ *that);
void __onDestroy(struct _ *that);
void __onKernels(struct _ *that);
struct arrayObject __getReaders(void *t);
void __setReadData(void *t, bufferReadData *readData);

struct runnablesContainer_cnets_osblinnikov_github_com __getRunnables(struct _ *that){
  return that->_runnables;
}

struct arrayObject __getReaders(void *t){
  struct _ *that = (struct _*)t;
  return that->_arrReaders_;
}


void __setReadData(void *t, bufferReadData *readData){
  struct _ *that = (struct _*)t;
  that->_readData = readData;
}


void __init(struct _ *that,
    _arrayObject _subscribedBuffersNames,
    _int32_t _maxNodesCount,
    writer _wlocalBuffers0,
    reader _rconnectionStatus0,
    reader _rreceiveRemoteRepository1,
    reader _rinput2){
  that->_readData = NULL;
  
  that->subscribedBuffersNames = _subscribedBuffersNames;
  that->maxNodesCount = _maxNodesCount;
  that->_arrReaders_ = arrayObject_init_dynamic(sizeof(reader), 3);
  ((reader*)that->_arrReaders_.array)[0] = _rconnectionStatus0;
  ((reader*)that->_arrReaders_.array)[1] = _rreceiveRemoteRepository1;
  ((reader*)that->_arrReaders_.array)[2] = _rinput2;
  selector_cnets_osblinnikov_github_com_init(&that->readersSelector, that->_arrReaders_);
  that->rSelect = selector_cnets_osblinnikov_github_com_createReader(&that->readersSelector, 0);
  that->wlocalBuffers0 = _wlocalBuffers0;
  that->rconnectionStatus0 = _rconnectionStatus0;
  that->rreceiveRemoteRepository1 = _rreceiveRemoteRepository1;
  that->rinput2 = _rinput2;
  
  __onKernels(that);
  
  that->getRunnables = __getRunnables;
  
    runnablesContainer_cnets_osblinnikov_github_com_init(&that->_runnables);
    RunnableStoppable_create(runnableStoppableObj,that, _)
    that->_runnables.setCore(&that->_runnables,runnableStoppableObj, 0);
  __onCreate(that);
}

void __deinit(struct _ *that){
  __onDestroy(that);
  
  arrayObject_free_dynamic(that->readersSelector.reducableReaders);
  selector_cnets_osblinnikov_github_com_deinit(&that->readersSelector);
}

/*[[[end]]] (checksum: 434e229051a117432c2eb7cbb44e96fb)*/

void __run(void *t){
  /*struct _ *that = (struct _*)t;*/
}

void __onStart(void *t){
  /*struct _ *that = (struct _*)t;*/
}

void __onStop(void *t){
  /*struct _ *that = (struct _*)t;*/
}

void __onCreate(struct _ *that){
  
  return;
}

void __onDestroy(struct _ *that){
  
  return;
}

void __onKernels(struct _ *that){
  
  return;
}
