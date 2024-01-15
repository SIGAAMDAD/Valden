#ifndef __MAP__
#define __MAP__

#pragma once

typedef enum {
    TU_DIFFUSEMAP,
    TU_NORMALMAP,
    TU_SPECULARMAP,

    NUMUNITS
} textureunit_t;

typedef struct {
    char name[MAX_NPATH];

    mapcheckpoint_t checkpoints[MAX_MAP_CHECKPOINTS];
    mapspawn_t spawns[MAX_MAP_SPAWNS];
    maplight_t lights[MAX_MAP_LIGHTS];

    tile2d_info_t tileset;
    tile2d_sprite_t *texcoords;
    maptile_t *tiles;

    Walnut::CShader *shader;
    Walnut::Image *textures[Walnut::NUM_TEXTURE_BUNDLES];

    vec3_t ambientColor;
    float ambientIntensity;

    int width;
    int height;

    int numTiles;
    int numLights;
    int numCheckpoints;
    int numSpawns;
} mapData_t;

extern mapData_t *mapData;
extern std::unordered_map<std::string, mapData_t> g_MapCache;

void Map_Init( void );
void Map_Save( void );

void Map_LoadFile( const char *filename );

void Map_Resize( void );

void Map_New( void );
void Map_Free( void );

void Map_BuildTileset( void );

void Map_ImportFile( const char *filename );
void Map_SaveSelected( const char *filename );

void Map_Import( IDataStream *in, const char *type );
void Map_Export( IDataStream *out, const char *type );

#endif