#pragma once
#include <IwGx.h>
#include <s3e.h>
#include <SCMLpp.h>
#include <SCML_marmalade.h>
#include <list>
#include <vector>

inline int64 getTime(){
    int64 time;
    if((time = s3eTimerGetUSTNanoseconds()) != -1)
        return time/1000000;
    return s3eTimerGetUST();
};

using namespace std;
using namespace SCML_MARMALADE;

void testSCMLMarmalade()
{
    //load data
    string data_file = "monster/Example.SCML";
    //string data_file = "knight/knight.scml";
    //string data_file = "hero/Hero.SCML";

    size_t data_file_index = 0;
    SCML::Data data(data_file);
    data.log();
    
    FileSystem fs;
    fs.load(&data);
    printf("Loaded %d images.\n", fs.images.size());
    
    list<Entity*> entities;
    for(map<int, SCML::Data::Entity*>::iterator e = data.entities.begin(); e != data.entities.end(); e++)
    {
        Entity* entity = new Entity(&data, e->first);
        entity->setFileSystem(&fs);
        //entity->setScreen( CIwGxSurface);
        entities.push_back(entity);
    }
    printf("Loaded %d entities.\n", entities.size());


    int64 oldTime = getTime();
    while(true)
    {
        s3eKeyboardUpdate();
        if((s3eKeyboardGetState(s3eKeyEsc) & S3E_KEY_STATE_PRESSED) || (s3eKeyboardGetState(s3eKeyAbsBSK) & S3E_KEY_STATE_PRESSED)) break;
        s3eDeviceBacklightOn();

        //update & render
        for(list<Entity*>::iterator e = entities.begin(); e != entities.end(); e++)
        {
            (*e)->update(getTime()-oldTime);
        }
        oldTime = getTime();
        IwGxClear();
        for(list<Entity*>::iterator e = entities.begin(); e != entities.end(); e++)
        {
            (*e)->draw(500.f,500.f);
        }
        IwGxSwapBuffers();
        s3eDeviceYield();
    }
    
    //free data
    for(list<Entity*>::iterator e = entities.begin(); e != entities.end(); e++)
    {
        delete (*e);
    }
    entities.clear();
    
    data.clear();

}