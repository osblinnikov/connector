/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../serializer.h"
/*[[[end]]] (checksum: a93734350291f341ed667dbb75c79241)*/
int main(int argc, char* argv[]){
  serializer_connector_osblinnikov_github_com classObj;
  serializer_connector_osblinnikov_github_com_init(&classObj,arrayObjectNULL(),0,writerNULL(),readerNULL(),readerNULL(),readerNULL());
    runnablesContainer_cnets_osblinnikov_github_com runnables = classObj.getRunnables(&classObj);
    runnables.launch(&runnables,TRUE);
    serializer_connector_osblinnikov_github_com_deinit(&classObj);
  return 0;
}
