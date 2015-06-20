#ifndef connectionStatusDispatcher_connector_osblinnikov_github_com_H
#define connectionStatusDispatcher_connector_osblinnikov_github_com_H

/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "github.com/osblinnikov/cnets/selector/selector.h"
#include "github.com/osblinnikov/cnets/mapBuffer/mapBuffer.h"
#include "github.com/osblinnikov/cnets/queue/queue.h"
#include "github.com/osblinnikov/cnets/runnablesContainer/runnablesContainer.h"
#include "github.com/osblinnikov/cnets/types/types.h"
#include "github.com/osblinnikov/connector/types/types.h"
#include "github.com/osblinnikov/cnets/readerWriter/readerWriter.h"
#include "github.com/osblinnikov/cnets/vector/vector.h"

#undef connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API
#if defined WIN32 && !defined __MINGW32__ && !defined(CYGWIN) && !defined(CONNECTIONSTATUSDISPATCHER_CONNECTOR_OSBLINNIKOV_GITHUB_COM_STATIC)
  #ifdef connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT
    #define connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API __declspec(dllexport)
  #else
    #define connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API __declspec(dllimport)
  #endif
#else
  #define connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API extern
#endif

struct connectionStatusDispatcher_connector_osblinnikov_github_com;

connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API
void connectionStatusDispatcher_connector_osblinnikov_github_com_init(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that,
    writer _wpublishExternally0,
    reader _rinputStatus0);

connectionStatusDispatcher_connector_osblinnikov_github_com_EXPORT_API
void connectionStatusDispatcher_connector_osblinnikov_github_com_deinit(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that);

typedef struct connectionStatusDispatcher_connector_osblinnikov_github_com{
  bufferReadData *_readData;
  writer wpublishExternally0;
  reader rinputStatus0;

  
  struct runnablesContainer_cnets_osblinnikov_github_com (*getRunnables)(struct connectionStatusDispatcher_connector_osblinnikov_github_com *that);
  struct runnablesContainer_cnets_osblinnikov_github_com _runnables;
/*[[[end]]] (checksum: 284fe5f3cae494a4c834a09cccf95f8f)*/

}connectionStatusDispatcher_connector_osblinnikov_github_com;

#endif /* connectionStatusDispatcher_connector_osblinnikov_github_com_H */