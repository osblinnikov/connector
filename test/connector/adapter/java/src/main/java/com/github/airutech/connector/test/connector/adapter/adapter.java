
package com.github.airutech.connector.test.connector.adapter;

/*[[[cog
import cogging as c
c.tpl(cog,templateFile,c.a(prefix=configFile))
]]]*/

import com.github.airutech.cnetsTransports.types.*;
import com.github.airutech.cnets.types.*;
import com.github.airutech.cnets.selector.*;
import com.github.airutech.cnets.readerWriter.*;
import com.github.airutech.cnets.runnablesContainer.*;
public class adapter implements RunnableStoppable{
  String[] publishedBuffersNames;String[] subscribedBuffersNames;serializeStreamCallback[] serializers;deserializeStreamCallback[] deserializers;writer w0;writer w1;reader r0;reader r1;reader r2;
  
  public adapter(String[] publishedBuffersNames,String[] subscribedBuffersNames,serializeStreamCallback[] serializers,deserializeStreamCallback[] deserializers,writer w0,writer w1,reader r0,reader r1,reader r2){
    this.publishedBuffersNames = publishedBuffersNames;
    this.subscribedBuffersNames = subscribedBuffersNames;
    this.serializers = serializers;
    this.deserializers = deserializers;
    this.w0 = w0;
    this.w1 = w1;
    this.r0 = r0;
    this.r1 = r1;
    this.r2 = r2;
    onCreate();
    initialize();
  }

  private void initialize(){
    /**/
    onKernels();
    /**/
  }
  public runnablesContainer getRunnables(){
    
    runnablesContainer runnables = new runnablesContainer();
    runnables.setCore(this);
    return runnables;
  }
/*[[[end]]] (checksum: f0893cf13f798d0294ba77aeaf5d1cf5)*/

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

