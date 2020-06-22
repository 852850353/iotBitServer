#ifndef MAPPINGFILE_H
#define MAPPINGFILE_H

#include <cstdlib>
#include <iostream>

namespace MappingFile
{

//持久化数据加载
template<typename T> bool load(std::string file,T& attrMem);

//持久化数据保存
template<typename T> bool save(std::string file,T& attrMem);

}
#endif // MAPPINGFILE_H
