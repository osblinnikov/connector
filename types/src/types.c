/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

#include "../types.h"
void types_connector_osblinnikov_github_com_onCreate(types_connector_osblinnikov_github_com *that);
void types_connector_osblinnikov_github_com_onDestroy(types_connector_osblinnikov_github_com *that);
void types_connector_osblinnikov_github_com_init(struct types_connector_osblinnikov_github_com *that){
  
  that->test = 10;
  types_connector_osblinnikov_github_com_onCreate(that);
}

void types_connector_osblinnikov_github_com_deinit(struct types_connector_osblinnikov_github_com *that){
  types_connector_osblinnikov_github_com_onDestroy(that);
  
}
/*[[[end]]] (checksum: 9946f284998723880e77606ea814c528)*/

void types_connector_osblinnikov_github_com_onCreate(types_connector_osblinnikov_github_com *that){
  
  return;
}

void types_connector_osblinnikov_github_com_onDestroy(types_connector_osblinnikov_github_com *that){
  
  return;
}