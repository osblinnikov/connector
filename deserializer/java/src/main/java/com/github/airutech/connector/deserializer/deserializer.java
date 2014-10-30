
package com.github.airutech.connector.deserializer;

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
public class deserializer implements RunnableStoppable{
  String[] subscribedBuffersNames;int maxNodesCount;writer w0;reader r0;reader r1;reader r2;reader rSelect;selector readersSelector;
  
  public deserializer(String[] subscribedBuffersNames,int maxNodesCount,writer w0,reader r0,reader r1,reader r2){
    this.subscribedBuffersNames = subscribedBuffersNames;
    this.maxNodesCount = maxNodesCount;
    this.w0 = w0;
    this.r0 = r0;
    this.r1 = r1;
    this.r2 = r2;
    reader[] arrReaders = new reader[3];
    arrReaders[0] = r0;
    arrReaders[1] = r1;
    arrReaders[2] = r2;
    this.readersSelector = new selector(arrReaders);
    this.rSelect = readersSelector.getReader(0,-1);
    onCreate();
    initialize();
  }

  private void initialize(){
    
    onKernels();
    
  }
  public runnablesContainer getRunnables(){
    
    runnablesContainer runnables = new runnablesContainer();
    runnables.setCore(this);
    return runnables;
  }
/*[[[end]]] (checksum: 41bf436c3b9f00b6497f85aed8945c7f)*/

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

