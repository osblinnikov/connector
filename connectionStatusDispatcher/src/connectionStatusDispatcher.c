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
void connectionStatusDispatcher_connector_osblinnikov_github_com_setReadData(void *t, bufferReadData *readData);

struct runnablesContainer_cnets_osblinnikov_github_com connectionStatusDispatcher_connector_osblinnikov_github_com_getRunnables(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that){
  return that->_runnables;
}

struct arrayObject connectionStatusDispatcher_connector_osblinnikov_github_com_getReaders(void *t){
  struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;
  return arrayObjectNULL();
}


void connectionStatusDispatcher_connector_osblinnikov_github_com_setReadData(void *t, bufferReadData *readData){
  struct connectionStatusDispatcher_connector_osblinnikov_github_com *that = (struct connectionStatusDispatcher_connector_osblinnikov_github_com*)t;
  that->_readData = readData;
}


void connectionStatusDispatcher_connector_osblinnikov_github_com_init(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that,
    writer _wpublishExternally0,
    reader _rinputStatus0){
  that->_readData = NULL;
  
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
  
}

/*[[[end]]] (checksum: 6a98b6974c835efd466fc9f242d61e11)*/

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
