
package com.github.airutech.connector.test.connector.adapter;
import org.junit.Test;
/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/


import com.github.airutech.cnetsTransports.types.*;
import com.github.airutech.cnets.types.*;
import com.github.airutech.cnets.selector.*;
import com.github.airutech.cnets.readerWriter.*;
import com.github.airutech.cnets.runnablesContainer.*;
/*[[[end]]] (checksum: 03012fadf78bfcc71b639ba62a1f833f)*/
public class adapterTest {
  @Test
  public void adapterTest(){
    adapter classObj = new adapter(new String[1],new String[1],new serializeStreamCallback[1],new deserializeStreamCallback[1],null,null,null,null,null);
  }
}

