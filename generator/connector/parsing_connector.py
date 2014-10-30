from gernetHelpers import *
import os
from attrs import *

def parsingGernet(a):
    a.read_data = None
    a.read_data = readJson(a.prefix)
    parsingData(a)
    try:
        a.gen = attrs()
        a.gen.read_data = readJson(a.prefix.replace("gernet.json",os.path.join("connector","gernet.json")))
        parsingData(a.gen)
    except:
        print "not parsed\n"

def parsingData(a):
    fullName = a.read_data["path"]
    a.version = a.read_data["ver"]
    fullNameList = fullName.split('.')
    a.fullName_ = '_'.join(fullNameList)
    a.className = fullNameList[-1]
    a.companyDomain = fullNameList[1]+'.'+fullNameList[0]
    a.company = fullNameList[1]

    del fullNameList[-1]
    a.domainName = '.'.join(fullNameList)

    fullNameList = fullName.split('.')
    to_delete = [0,1]
    for offset, index in enumerate(to_delete):
        index -= offset
        del fullNameList[index]
    a.domainPath = a.companyDomain+'/'+('/'.join(fullNameList))


def publishedBuffersCount(a):
    try:
        return len(a.gen.read_data["connection"]["writeTo"])-1
    except:
        return 0

def subscribedBuffersCount(a):
    try:
        return len(a.gen.read_data["connection"]["readFrom"])-1
    except:
        return 0

def nodeRepositoryProtocolSerializerPath(a):
    return a.read_data["nodeRepositoryProtocolSerializerPath"]

def socketPath(a):
    return a.read_data["socketPath"]

def serializerPath(a):
    return a.read_data["serializerPath"]

def getObjConnections(a, withBlockIds):
    obj = attrs()
    #WRITERS STARTS HERE
    obj.writeTo = []
    inRepoProtocol = attrs()
    inRepoProtocol.name = "inRepoProtocol"
    inRepoProtocol.type = "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    if withBlockIds:
        inRepoProtocol.blockId = 1
        inRepoProtocol.pinId = 0
    obj.writeTo.append(inRepoProtocol)

    inLocalBuffers = attrs()
    inLocalBuffers.name = "inLocalBuffers"
    inLocalBuffers.type = "com.github.airutech.connector.types.localBuffers"
    if withBlockIds:
        inLocalBuffers.blockId = 9
        inLocalBuffers.pinId = 0
    obj.writeTo.append(inLocalBuffers)

    try:
        for i,v in enumerate(a.gen.read_data["connection"]["writeTo"]):
            if i == 0:
                continue
            exported = attrs()
            if v.has_key("name"):
                exported.name = v["name"]
            exported.type = v["type"]
            if withBlockIds:
                exported.blockId = "export"
                exported.pinId = i
            obj.writeTo.append(exported)
    except:
        print "writers not generated, try again\n"

    #READERS STARTS HERE
    obj.readFrom = []
    outRepoProtocol = attrs()
    outRepoProtocol.name = "outRepoProtocol"
    outRepoProtocol.type = "com.github.airutech.cnetsTransports.nodeRepositoryProtocol.nodeRepositoryProtocol"
    obj.readFrom.append(outRepoProtocol)

    localBuffers = attrs()
    localBuffers.name = "localBuffers"
    localBuffers.type = "com.github.airutech.connector.types.localBuffers"
    obj.readFrom.append(localBuffers)

    try:
        for i,v in enumerate(a.gen.read_data["connection"]["readFrom"]):
            if i == 0:
                continue
            exported = attrs()
            if v.has_key("name"):
                exported.name = v["name"]
            exported.type = v["type"]
            if withBlockIds:
                exported.blockId = "export"
                exported.pinId = i
            obj.readFrom.append(exported)

    except:
        print "readers not generated, try again\n"

    return obj

def getConnections(a):
    return json.dumps( getObjConnections(a, False) )

def adapterConnections(a):
    return json.dumps( getObjConnections(a, True) )