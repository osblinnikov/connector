<%
import sys
sys.path.insert(0, a.parserPath)

import parsing_java
p = reload(parsing_java)
p.parsingGernet(a)

%>
package ${a.read_data["path"]};

/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/
/*[[[end]]]*/

  private void onCreate(){

  }

  private void onKernels(){

  }

  @Override
  public void onStart(){

  }

  @Override
  public void run(){

  }

  @Override
  public void onStop(){

  }

}

