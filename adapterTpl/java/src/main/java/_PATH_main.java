<%
import sys
sys.path.insert(0, a.parserPath)

import parsing_java
p = reload(parsing_java)
p.parsingGernet(a)

%>
package ${a.read_data["path"]};
import ${a.read_data["path"]}.${a.className};
/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/
/*[[[end]]]*/
public class main{
  public static void main(String[] args){
    ${p.startRunnables(a)}
  }
}
