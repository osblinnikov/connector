/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../connectionStatusDispatcher.h"
#include <stdlib.h>

void connectionStatusDispatcher_connector_osblinnikov_github_com_run(void *that);
void connectionStatusDispatcher_connector_osblinnikov_github_com_onStart(void *that);
void connectionStatusDispatcher_connector_osblinnikov_github_com_onStop(void *that);
void connectionStatusDispatcher_connector_osblinnikov_github_com_onCreate(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that);
void connectionStatusDispatcher_connector_osblinnikov_github_com_onDestroy(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that);
void connectionStatusDispatcher_connector_osblinnikov_github_com_onKernels(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that);
struct arrayObject connectionStatusDispatcher_connector_osblinnikov_github_com_getReaders(void *t);

struct runnablesContainer_cnets_osblinnikov_github_com connectionStatusDispatcher_connector_osblinnikov_github_com_getRunnables(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  return that->_runnables;
}

struct arrayObject connectionStatusDispatcher_connector_osblinnikov_github_com_getReaders(void *t){
  struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;
  arrayObject arr;
  arr.length = 1;
  arr.itemSize = sizeof(reader);
  arr.array = (void*)&that->rSelect;
  return arr;
}


void connectionStatusDispatcher_connector_osblinnikov_github_com_init(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that,
    writer _wpublishExternally0,
    reader _rinputStatus0){
  
  that->_arrReaders_ = arrayObject_init_dynamic(sizeof(reader), 1);
  ((reader*)that->_arrReaders_.array)[0] = _rinputStatus0;
  selector_cnets_osblinnikov_github_com_init(&that->readersSelector, that->_arrReaders_);
  that->rSelect = selector_cnets_osblinnikov_github_com_createReader(&that->readersSelector, 0);
  that->wpublishExternally0 = _wpublishExternally0;
  that->rinputStatus0 = _rinputStatus0;
  
  connectionStatusDispatcher_connector_osblinnikov_github_com_onKernels(that);
  
  that->getRunnables = connectionStatusDispatcher_connector_osblinnikov_github_com_getRunnables;
  
    runnablesContainer_cnets_osblinnikov_github_com_init(&that->_runnables);
    RunnableStoppable_create(runnableStoppableObj,that, connectionStatusDispatcher_connector_osblinnikov_github_com)
    that->_runnables.setCore(&that->_runnables,runnableStoppableObj, 0);
  connectionStatusDispatcher_connector_osblinnikov_github_com_onCreate(that);
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_deinit(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  connectionStatusDispatcher_connector_osblinnikov_github_com_onDestroy(that);
  
  arrayObject_free_dynamic(that->readersSelector.reducableReaders);
  selector_cnets_osblinnikov_github_com_deinit(&that->readersSelector);
}

/*[[[end]]] (checksum: c18b07b57b5251bd3c123b664f8de501)*/

void connectionStatusDispatcher_connector_osblinnikov_github_com_run(void *t){
  /*struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;*/
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_onStart(void *t){
  /*struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;*/
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_onStop(void *t){
  /*struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;*/
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_onCreate(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  
  return;
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_onDestroy(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  
  return;
}

void connectionStatusDispatcher_connector_osblinnikov_github_com_onKernels(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  
  return;
}
