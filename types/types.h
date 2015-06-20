

#ifndef types_connector_osblinnikov_github_com_H
#define types_connector_osblinnikov_github_com_H

/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/


#undef types_connector_osblinnikov_github_com_EXPORT_API
#if defined WIN32 && !defined __MINGW32__ && !defined(CYGWIN) && !defined(TYPES_CONNECTOR_OSBLINNIKOV_GITHUB_COM_STATIC)
  #ifdef types_connector_osblinnikov_github_com_EXPORT
    #define types_connector_osblinnikov_github_com_EXPORT_API __declspec(dllexport)
  #else
    #define types_connector_osblinnikov_github_com_EXPORT_API __declspec(dllimport)
  #endif
#else
  #define types_connector_osblinnikov_github_com_EXPORT_API extern
#endif

struct types_connector_osblinnikov_github_com;

types_connector_osblinnikov_github_com_EXPORT_API
void types_connector_osblinnikov_github_com_init(struct types_connector_osblinnikov_github_com *that);

types_connector_osblinnikov_github_com_EXPORT_API
void types_connector_osblinnikov_github_com_deinit(struct types_connector_osblinnikov_github_com *that);

typedef struct types_connector_osblinnikov_github_com{
    _int32_t test;

  
/*[[[end]]] (checksum: 17ab31e9e39a2a69daa98466c1800b4a)*/

}types_connector_osblinnikov_github_com;

#endif /* types_connector_osblinnikov_github_com_H */