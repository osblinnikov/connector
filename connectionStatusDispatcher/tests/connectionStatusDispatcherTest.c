/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../connectionStatusDispatcher.h"
/*[[[end]]] (checksum: 6d669953c4a1892cdcfd0aefd98d3168)*/
int main(int argc, char* argv[]){
  connectionStatusDispatcher_connector_osblinnikov_github_com classObj;
  connectionStatusDispatcher_connector_osblinnikov_github_com_init(&classObj,writerNULL(),readerNULL());
    runnablesContainer_cnets_osblinnikov_github_com runnables = classObj.getRunnables(&classObj);
    runnables.launch(&runnables,FALSE);
    runnables.stop(&runnables);
    connectionStatusDispatcher_connector_osblinnikov_github_com_deinit(&classObj);
  return 0;
}