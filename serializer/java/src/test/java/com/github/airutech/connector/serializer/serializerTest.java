
package com.github.airutech.connector.serializer;
import org.junit.Test;
/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/


import com.github.airutech.cnetsTransports.types.*;
import com.github.airutech.cnets.selector.*;
import com.github.airutech.cnets.queue.*;
import com.github.airutech.cnetsTransports.nodeRepositoryProtocol.*;
import com.github.airutech.cnets.readerWriter.*;
import com.github.airutech.cnets.runnablesContainer.*;
import com.github.airutech.cnets.types.*;
import com.github.airutech.cnets.mapBuffer.*;
/*[[[end]]] (checksum: 73b0f13afa19ad49cdb54b485e3c8b7d)*/
public class serializerTest {
  @Test
  public void serializerTest(){
    serializer classObj = new serializer(new String[1],0,null,null,null,null);
  }
}

