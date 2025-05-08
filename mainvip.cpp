#include "Includes.h"
#include "obfuscate.h"
#include "Tools.h"
#include "fake_dlfcn.h"
#include "imgui/imgui.h"
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h"
#include "StrEnc.h"
#include "Items.h"
#include "Iconcpp.h"
#include "ImguiPP.h"
#include "Menu.h"
#include "Icon.h"
#include "Font.h"
#include "Colors.h"
#include "json.hpp"
#include "SDK.hpp"
#include "Nhkmod.h"
#include "Dobby64/dobby.h"
#include "Helper/Vector3.hpp"
//#include "Tools.h"
#include "KittyMemory/MemoryPatch.h"
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include "base64/base64.h"
#include "Ayanfont.h"
#define STB_IMAGE_IMPLEMENTATION
#include "IMAGE/Logo.h"
#include "imgui/stb_image.h"
using namespace SDK;
#define SLEEP_TIME 1000LL / 60LL
using json = nlohmann::json;
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl

float AimSmooth = 3.8f;



void AimBotS(FRotator &angles) {
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;

    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;

    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}
void AimBotS(float *angles) {
    if (angles[0] > 180)
        angles[0] -= 360;
    if (angles[0] < -180)
        angles[0] += 360;

    if (angles[0] < -75.f)
        angles[0] = -75.f;
    else if (angles[0] > 75.f)
        angles[0] = 75.f;

    while (angles[1] < -180.0f)
        angles[1] += 360.0f;
    while (angles[1] > 180.0f)
        angles[1] -= 360.0f;
}


void AimBotS(Vector3 angles) {
    if (angles.X > 180)
        angles.X -= 360;
    if (angles.X < -180)
        angles.X += 360;

    if (angles.X < -75.f)
        angles.X = -75.f;
    else if (angles.X > 75.f)
        angles.X = 75.f;

    while (angles.Y < -180.0f)
        angles.Y += 360.0f;
    while (angles.Y > 180.0f)
        angles.Y -= 360.0f;
}long GetEpochTime()
    {
    auto duration = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    }
    
    
    
    

                                            
bool FASTPERA;
static bool isFlyModeEnabled = false;
static float isRed = 0.0f, isGreen = 0.01f, isBlue = 0.0f;
ImColor outlinecolor = IM_COL32(10, 10, 10, 255);

#define GNames_Offset 0x46DD824
#define GUObject_Offset 0x95AEF18
#define GNativeAndroidApp_Offset 0x93e72b8
#define ProccesEvent_Offset 0x614f49c
#define GetActorArray 0x65e6e28
#define ViewMatrix_Offset = 0x97DFFF0
#define Actors_Offset 0x70
/*

#define LocalPlayer_Offset = 0x8d029d0
*/
/*
#define GNames_Offset 
#define GEngine_Offset 0x8ab0b70 //UEngine
#define GUObject_Offset 
#define GetActorArray_Offset 
#define GNativeAndroidApp_Offset 
#define Actors_Offset 0x70
//#define SwapBuffers 0x7B54050

*/
bool island = false;
json items_data;
std::string g_Token, g_Auth;
bool bValid = false;
std::string errMsg;
uintptr_t UE4;

ImFont* NHKModFont;
ImFont* Ayanfont;

android_app *g_App = 0;
ASTExtraPlayerCharacter *g_LocalPlayer = 0;
ASTExtraPlayerController *g_LocalController = 0;
std::string expiredDate = "";
std::string modname ="";
std::string device = "";
std::string mod_status = "";
std::string floting ="";
std::string date;
static std::string EXP = " ";
static float Size = 200;
bool HIDEESP = true;
bool Lobby = true;
 bool BypassNHK = true;
bool initImGui = false;
bool show_another_window2 = false;
static bool HideWindow = true;
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;
json mItemData; 
float FOVSizea = 100;
float Skill = 4;
float Sland = 15000;
float sinstanthit = 100000;
static bool IgnoreBot = false;
 
enum EAimMode {
    AimBullet = 0,
    Pbullet = 1,
    AimBot = 2
};

enum EAimTarget {
    Chest = 0,
    Head = 1

};
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl


enum EAimBy {
    FOV = 0,
    Distance = 1
};

enum EAimTrigger {
	Shooting = 0,
    None = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};

std::map<int, bool> Items;
std::map<int, float *> ItemColors;

struct sConfig {
	bool EnimiesAlertNhk;
	bool Ipad;
	bool smooothFPS;
    struct sPlayerESP {
        bool ECount;
        bool Line;
		bool Box;
		bool DistanceMax;
		bool Health;
		bool Skeleton;
		bool Name;
		bool Distance;
		bool TeamID;
		bool Grenade;
		bool Vehicle;
		bool NoBot;
		bool VehicleHP;
		bool VehicleFuel;
	    bool OneClickEsp;	
		bool LootBox;
		bool Radar;
	    bool Flash;
		bool LootBoxItems;	
        bool wideview;
        bool sfps;
		bool AutoFire;
		bool online;
		
    };
    sPlayerESP PlayerESP{0};

    struct sVehicleESP {
        bool ShowVehicle;
        bool ShowDistance;
    };
    sVehicleESP VehicleESP{0};

    struct sAimMenu {
        bool Enable;
		bool AimBot;
        EAimMode Mode;
        EAimBy AimBy;
        EAimTarget Target;
        EAimTrigger Trigger;
		bool RecoilComparison;
        float Recc;
		float Line;
		float Meter;
        bool Prediction;
        float Cross;
		float Crosss;
        bool IgnoreKnocked;
        bool VisCheck;
		bool IgnoreBot;
    };
    sAimMenu SilentAim{0};
    sAimMenu AimBot{0};
	
    struct sHighRisk {
        bool Shake;
        bool Recoil;
        bool Instant;
        bool HitEffect;
        bool Flash;
        bool Parachute;
    };
    sHighRisk HighRisk{0};

    struct sColorsESP {
        float *Line;
        float *Box;
        float *Name;
        float *Distance;
        float *Skeleton;
        float *SkeletonVisible;
        float *BotNn;
	    float *Skeletonbot;
	    float *nonbot;
        float *Skeletonnon;
        float *BotNv;
        float *PotNn;
        float *PotNv;
        float *Vehicle;
    };
    sColorsESP ColorsESP{0};
	
	struct sOTHER {
        bool FPS;
        bool HIDEESP;
        bool EXPIRYTIME;
    };
    sOTHER OTHER{0};
};




    struct TextureInfo { ImTextureID textureId; int x; int y; int w; int h; };
    void DrawImage(int x, int y, int w, int h, ImTextureID Texture) {
    ImGui::GetForegroundDrawList()->AddImage(Texture, ImVec2(x, y), ImVec2(x + w, y + h));}
    
    
    


    
    
//===========| 𝗜𝗠𝗔𝗚𝗘 𝗙𝗥𝗢𝗠 𝗦𝗧𝗢𝗥𝗔𝗚𝗘 
    
    static TextureInfo textureInfo;
    TextureInfo createTexture(char *ImagePath) {
    int w, h, n;
    stbi_uc *data = stbi_load(ImagePath, &w, &h, &n, 0);
    GLuint texture;
    glGenTextures(1, &texture);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    if (n == 3) {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    } else {
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    }stbi_image_free(data);
    textureInfo.textureId = reinterpret_cast<ImTextureID>((GLuint *) texture);
    textureInfo.w = w;
    textureInfo.h = h;
    return textureInfo;}

//===========| 𝗜𝗠𝗔𝗚𝗘 𝗙𝗥𝗢𝗠 𝗕𝗬𝗧𝗘 𝗔𝗥𝗥𝗔𝗬
    
    TextureInfo CreateTexture(const unsigned char* buf, int len) {
    TextureInfo image;
    unsigned char* image_data = stbi_load_from_memory(buf, len, &image.w, &image.h, NULL, 0);
    if (image_data == NULL) {perror("File does not exist");}
    GLuint image_texture;
    glGenTextures(1, &image_texture);
    glBindTexture(GL_TEXTURE_2D, image_texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    #if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
    glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
    #endif
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.w, image.h, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    stbi_image_free(image_data);
    image.textureId = (ImTextureID)image_texture;
    return image;}
    
//==============| 𝗧𝗘𝗫𝗧𝗨𝗥𝗘 𝗗𝗘𝗙𝗜𝗡𝗘
    
TextureInfo Logo;


void InitTexture() {
Logo = CreateTexture(Logo_data, sizeof(Logo_data));

}
















sConfig Config{0};
#define CREATE_COLOR(r, g, b, a) new float[4] {(float)r, (float)g, (float)b, (float)a};
 static UEngine *GEngine = 0;
UWorld *GetWorld() {
    while (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1"); // Auto 
        sleep(1);
    }
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;

        if (ViewPort) {
   //return {};
            return ViewPort->World;
        }
    }
    return 0;
}


TNameEntryArray *GetGNames() {
    return ((TNameEntryArray *(*)()) (UE4 + GNames_Offset))();
}

std::vector<AActor *> getActors() {
    auto World = GetWorld();
    if (!World)
        return std::vector<AActor *>();

    auto PersistentLevel = World->PersistentLevel;
    if (!PersistentLevel)
        return std::vector<AActor *>();

    auto Actors = *(TArray<AActor *> *)((uintptr_t) PersistentLevel + Actors_Offset);

    std::vector<AActor *> actors;
    for (int i = 0; i < Actors.Num(); i++) {
        auto Actor = Actors[i];
        if (Actor) {
            actors.push_back(Actor);
        }
    }
    return actors;
}
 
struct sRegion {
    uintptr_t start, end;
};

std::vector<sRegion> trapRegions;

bool isObjectInvalid(UObject *obj) {
    if (!Tools::IsPtrValid(obj)) {
        return true;
    }

    if (!Tools::IsPtrValid(obj->ClassPrivate)) {
        return true;
    }

    if (obj->InternalIndex <= 0) {
        return true;
    }

    if (obj->NamePrivate.ComparisonIndex <= 0) {
        return true;
    }

    if ((uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4) {
        return true;
    }

    if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj) >= region.start && ((uintptr_t) obj) <= region.end; }) ||
        std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t) obj->ClassPrivate) >= region.start && ((uintptr_t) obj->ClassPrivate) <= region.end; })) {
        return true;
    }

    return false;
}

typedef void (*ImGuiDemoMarkerCallback)(const char* file, int line, const char* section, void* user_data);
extern ImGuiDemoMarkerCallback  GImGuiDemoMarkerCallback;
extern void* GImGuiDemoMarkerCallbackUserData;
ImGuiDemoMarkerCallback         GImGuiDemoMarkerCallback = NULL;
void* GImGuiDemoMarkerCallbackUserData = NULL;
#define IMGUI_DEMO_MARKER(section)  do { if (GImGuiDemoMarkerCallback != NULL) GImGuiDemoMarkerCallback(__FILE__, __LINE__, section, GImGuiDemoMarkerCallbackUserData); } while (0)
ImGuiStyle& style = ImGui::GetStyle();
static ImGuiStyle ref_saved_style;
 
std::string getObjectPath(UObject *Object) {
    std::string s;
    for (auto super = Object->ClassPrivate; super; super = (UClass *) super->SuperStruct) {
        if (!s.empty())
            s += ".";
        s += super->NamePrivate.GetName();
    }
    return s;
}
 
int32_t ToColor(float *col) {
    return ImGui::ColorConvertFloat4ToU32(*(ImVec4 *) (col));
}

FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = UKismetMathLibrary::Subtract_VectorVector(local, target);

    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);

    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;

    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;

    return newViewAngle;
}



 #define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(localController, w, true, s)

 int32_t (*orig_ANativeWindow_getWidth)(ANativeWindow *window);
int32_t _ANativeWindow_getWidth(ANativeWindow *window)
{
    screenWidth = orig_ANativeWindow_getWidth(window);
    return orig_ANativeWindow_getWidth(window);
}

void (*orig_onInputEvent)(void *thiz, void *ex_ab, void *ex_ac);
void onInputEvent(void *thiz, void *ex_ab, void *ex_ac)
{
    orig_onInputEvent(thiz, ex_ab, ex_ac);
    if (initImGui)
    {
        ImGui_ImplAndroid_HandleInputEvent((AInputEvent *)thiz, {(float)screenWidth / (float)glWidth, (float)screenHeight / (float)glHeight});
    }
    return;
}

int32_t (*orig_ANativeWindow_getHeight)(ANativeWindow *window);
int32_t _ANativeWindow_getHeight(ANativeWindow *window)
{
    screenHeight = orig_ANativeWindow_getHeight(window);
    return orig_ANativeWindow_getHeight(window);
}
bool isInsideFOVs(int x, int y) {
    if (!FOVSizea)
        return true;

    int circle_x = glWidth / 2;
    int circle_y = glHeight / 2;
    int rad = FOVSizea;
    return (x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad;
}
/*
auto GetTargetForAimBot() {
   ASTExtraPlayerCharacter *result = 0;
	float max = std::numeric_limits<float>::infinity();
	auto Actors = getActors();
	auto localPlayer = g_LocalPlayer;
	auto localController = g_LocalController;
	if (localPlayer)
	{

        for (auto Actor : Actors)
        {
            if (isObjectInvalid(Actor))
                continue;
            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
            {
                auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *) Actor;
                
                float dist = localPlayer->GetDistanceTo(Target) / 100.0f;

                if (dist > Config.AimBot.Meter)
					continue;
                
                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;
                if (Player->TeamID == localPlayer->TeamID)
                    continue;
                if (Player->bDead)
                    continue;

	
	/*
		for (auto Actor : Actors)
		{
			if (isObjectInvalid(Actor))
				continue;
			if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass()))
			{
				auto Player = (ASTExtraPlayerCharacter *)Actor;
				
				
		    if (dist > Config.Meter)
					continue;
					
				if (Player->PlayerKey == localPlayer->PlayerKey)
					continue;
				if (Player->TeamID == localPlayer->TeamID)
					continue;
				if (Player->bDead)
					continue;*/
					
					
                    /*          if (Config.AimBot.IgnoreKnocked) {
                            if (Player->Health == 0.0f)
                                continue;
                        }


                        if (Config.AimBot.VisCheck) {
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                                continue;
                        }
                        if (Config.AimBot.IgnoreBot) {
                            if (Player->bEnsure)
                                continue;
                        }

                        auto Root = Player->GetBonePos("Root", {});
				auto Head = Player->GetBonePos("Head", {});
				FVector2D RootSc, HeadSc;
				if (W2S(Root, &RootSc) && W2S(Head, &HeadSc))
				{
					float height = abs(HeadSc.Y - RootSc.Y);
					float width = height * 0.65f;

					FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
					if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight))
					{
						FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
						FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
						
						
                                if(isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {

                                float dist = FVector2D::Distance(v2Middle, v2Loc);

                                if (dist < max) {
                                    max = dist;
                                    result = Player;
                                }
                              }
                            }
                        }
            }
        }
    }

    return result;
}
*/

		auto GetTargetForAimBot() {
        ASTExtraPlayerCharacter *result = 0;
        float max = std::numeric_limits<float>::infinity();
        auto Actors = getActors();
        auto localPlayer = g_LocalPlayer;
        auto localController = g_LocalController;
        if (localPlayer) {
        for (auto Actor : Actors) {
        if (isObjectInvalid(Actor))
        continue;
        if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
        auto Player = (ASTExtraPlayerCharacter *) Actor;
        auto Target = (ASTExtraPlayerCharacter *) Actor;
        float dist = localPlayer->GetDistanceTo(Target) / 100.0f;    
        if (dist > Config.AimBot.Meter)
        continue;
        if (Player->PlayerKey == localPlayer->PlayerKey)
        continue;
        if (Player->TeamID == localPlayer->TeamID)
        continue;
        if (Player->bDead)
        continue;
        if (Config.AimBot.IgnoreKnocked) {
        if (Player->Health == 0.0f)
        continue;}
        if (Config.AimBot.VisCheck) {
        if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
        continue;}
        if (Config.AimBot.IgnoreBot) {
        if (Player->bIsAI)
        continue;}
        auto Root = Player->GetBonePos("Root", {});
        auto Head = Player->GetBonePos("Head", {});
        FVector2D RootSc, HeadSc;
        if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
        float height = abs(HeadSc.Y - RootSc.Y);
        float width = height * 0.65f;
        FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
        if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);
        if (isInsideFOVs((int) middlePoint.X, (int) middlePoint.Y)) {
        float dist = FVector2D::Distance(v2Middle, v2Loc);
        if (dist < max) {
        max = dist;
        result = Player;
        }}}}}}}return result;}
        
        
auto GetTargetByPussy() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto GWorld = GetWorld();
    if (GWorld) {
        ULevel *PersistentLevel = GWorld->PersistentLevel;
        if (PersistentLevel) {
            TArray<AActor *> Actors = *(TArray<AActor *> *) ((uintptr_t) PersistentLevel +
                                                             Actors_Offset);


            auto localPlayer = g_LocalPlayer;
            auto localController = g_LocalController;

            if (localPlayer) {
                for (int i = 0; i < Actors.Num(); i++) {
                    auto Actor = Actors[i];
                    if (isObjectInvalid(Actor))
                        continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.SilentAim.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }
        
                if (Config.SilentAim.IgnoreBot) {
                    if (Player->bEnsure)
                        continue;
                }
                  
                 
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                              continue;
      
                        float dist = g_LocalPlayer->GetDistanceTo(Player);
                             if (dist < max) {
                                 max = dist;
                              result = Player;
                        
							  }
                            }
                        }
                    }
                }
            }
        

    return result;
}


// DM BUY PRIVATE SOURCE  @DEVILHACKYT 
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// main channel https://t.me/+vEhRUxREo-oxMzhl
// Join Our Bypass Chennal https://t.me/+cICpy0QfzVAyNDY1

auto GetTargetByCrossDist() {
    ASTExtraPlayerCharacter *result = 0;
    float max = std::numeric_limits<float>::infinity();

    auto Actors = getActors();

    auto localPlayer = g_LocalPlayer;
    auto localController = g_LocalController;

    if (localPlayer) {
        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *) Actor;

                if (Player->PlayerKey == localPlayer->PlayerKey)
                    continue;

                if (Player->TeamID == localPlayer->TeamID)
                    continue;

                if (Player->bDead)
                    continue;

                if (Config.SilentAim.IgnoreKnocked) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Config.SilentAim.VisCheck) {
                    if (!localController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }
                if (Config.SilentAim.IgnoreBot) {
                    if (Player->bEnsure)
                        continue;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});

                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.65f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) && (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float) (glWidth / 2), (float) (glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                        float dist = FVector2D::Distance(v2Middle, v2Loc);

                        if (dist < max) {
                            max = dist;
                            result = Player;
                        }
                    }
                }
            }
        }
    }

    return result;
}


ASTExtraPlayerCharacter *GetTargetForAim() {
    if (Config.AimBot.AimBy == EAimBy::FOV) {
        return GetTargetByCrossDist();
    }

    return 0;
}


// DM BUY PRIVATE SOURCE  @DEVILHACKYT 
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// main channel https://t.me/+vEhRUxREo-oxMzhl
// Join Our Bypass Chennal https://t.me/+cICpy0QfzVAyNDY1

const char *GetVehicleName(ASTExtraVehicleBase *Vehicle) {
    switch (Vehicle->VehicleShapeType) {
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Motorbike_SideCart:
            return "Motorbike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Dacia:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyDacia:
            return "Dacia";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MiniBus:
            return "Mini Bus";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PickUp01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyPickup:
            return "Pick Up";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Buggy:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyBuggy:
            return "Buggy";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ01:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ02:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAZ03:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUAZ:
            return "UAZ";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_PG117:
            return "PG117";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Aquarail:
            return "Aquarail";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Mirado01:
            return "Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Rony:
            return "Rony";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Scooter:
            return "Scooter";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowMobile:
            return "Snow Mobile";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_TukTukTuk:
            return "Tuk Tuk";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_SnowBike:
            return "Snow Bike";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Surfboard:
            return "Surf Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Snowboard:
            return "Snow Board";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Amphibious:
            return "Amphibious";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_LadaNiva:
            return "Lada Niva";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_UAV:
            return "UAV";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_MegaDrop:
            return "Mega Drop";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini:
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_Lamborghini01:
            return "Lamborghini";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_GoldMirado:
            return "Gold Mirado";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_BigFoot:
            return "Big Foot";
            break;
        case ESTExtraVehicleShapeType::ESTExtraVehicleShapeType__VST_HeavyUH60:
            return "UH60";
            break;
        default:
            return "Vehicle";
            break;
    }
    return "Vehicle";
}
void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;

bool qwcifqvs86y8fify = false;

void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, ASTExtraShootWeapon *weapon, int unk1) {
if (qwcifqvs86y8fify) {
  qwcifqvs86y8fify = false;
  g_LocalController->bIsPressingFireBtn = false;
thiz->OwnerShootWeapon->StopFire(EFreshWeaponStateType::FreshWeaponStateType_Idle);
}




// DM BUY PRIVATE SOURCE  @DEVILHACKYT 
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// main channel https://t.me/+vEhRUxREo-oxMzhl
// Join Our Bypass Chennal https://t.me/+cICpy0QfzVAyNDY1


        if (Config.SilentAim.Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetByPussy();
        if (Target) {
            bool triggerOk = false;
            if (Config.SilentAim.Trigger != EAimTrigger::None) {
                if (Config.SilentAim.Trigger == EAimTrigger::Shooting) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Scoping) {
                    triggerOk = g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Both) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring && g_LocalPlayer->bIsGunADS;
                } else if (Config.SilentAim.Trigger == EAimTrigger::Any) {
                    triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
                }
            } else triggerOk = true;
            if (triggerOk) {
                FVector targetAimPos = Target->GetBonePos("Head", {});
                if (Config.SilentAim.Target == EAimTarget::Chest) {
                    targetAimPos.Z -= 25.0f;
                }

                UShootWeaponEntity *ShootWeaponEntityComponent = thiz->ShootWeaponEntityComponent;

				
			
                if (ShootWeaponEntityComponent) {
                    ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                    if (CurrentVehicle) {
                        FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
                    } else {
                        FVector Velocity = Target->GetVelocity();

                        float dist = g_LocalPlayer->GetDistanceTo(Target);
                        auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;

                        targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
                    }
                    FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
                    FRotator sex = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                    rot = sex;
                }
            }
        }
    }

    return orig_shoot_event(thiz, start, rot, weapon, unk1);
}

class FPSCounter {
protected:
    unsigned int m_fps;
    unsigned int m_fpscount;
    long m_fpsinterval;

public:
    FPSCounter() : m_fps(0), m_fpscount(0), m_fpsinterval(0) {
    }

    void update() {
        m_fpscount++;

        if (m_fpsinterval < time(0)) {
            m_fps = m_fpscount;

            m_fpscount = 0;
            m_fpsinterval = time(0) + 1;
        }
    }

    unsigned int get() const {
        return m_fps;
    }
};

FPSCounter fps;
#include <string>

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    if (!result.empty() && result[result.size() - 1] == '\n') {
        result.erase(result.size() - 1);
    }
    return result;
}

std::string getDeviceProperty(const std::string& property) {
    std::string command = "getprop " + property;
    return exec(command.c_str());
}

// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl

int SCOLOR, CounterColorByAYAN;

ImVec4 RainbowColor(float t)
{
    float r = 0.5f + 0.5f * sinf(2.0f * 3.14159f * t);
    float g = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.33f));
    float b = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.66f));
    return ImVec4(r, g, b, 1.0f);
}






void DrawESP(ImDrawList *draw) {
    
    //AYANxMOD:









    
    if (island) {/*
MemoryPatch::createWithHex("libhdmpve.so",0x3C36C,"00 00 80 D2 C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libhdmpve.so",0x3C3E4,"00 00 80 D2 C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libhdmpve.so",0x3C450,"00 00 80 D2 C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libhdmpve.so",0x3C45C,"00 00 80 D2 C0 03 5F D6").Modify();
MemoryPatch::createWithHex("libhdmpve.so",0x3C468,"00 00 80 D2 C0 03 5F D6").Modify();
*/
MemoryPatch::createWithHex("libhdmpve.so", 0x76F04,"00 20 70 47").Modify(); 
MemoryPatch::createWithHex("libhdmpve.so", 0xB99F8,"00 20 70 47").Modify(); //ISLAND
}
 
    
/*       
    if (island) {
    
    
				
	Config.PlayerESP.Line = true;
	Config.PlayerESP.Skeleton = true;
    Config.PlayerESP.Health = true;
	Config.PlayerESP.Name = true;
    Config.PlayerESP.Distance = true;
	Config.PlayerESP.TeamID = true;
    
    }else{
   Config.PlayerESP.Line = false;
	Config.PlayerESP.Skeleton = false;
    Config.PlayerESP.Health = false;
	Config.PlayerESP.Name = false;
    Config.PlayerESP.Distance = false;
	Config.PlayerESP.TeamID = false;  
     
    }
    */
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
/*
draw->AddText({((float) density / 12.0f), 18}, IM_COL32(0, 255, 0, 255),
"                               	          PLAY SAFE | AVOID REPORTS");*/
/*
time_t now = time(0);
tm* localTime = localtime(&now);
char buffer[80];
std::string formatString = "%A " + EXP + " %I:%M:%S %p";
strftime(buffer, 80, formatString.c_str(), localTime);
std::string finalString = std::string(buffer);*/
draw->AddText(NHKModFont, ((float)density / 10.0f), {(float)glWidth / 250 + glWidth / 40,680}, IM_COL32(252, 3, 3, 255) /*RainbowColor*/, "PLAY SAFE ] AVOID REPORTS");



float radius = 190.0f; // Circle ka radius
float centerX = glWidth / 2.0f; // Center X coordinate of the circle
float centerY = glHeight / 2.0f; // Center Y coordinate of the circle
float speed = 2.0f; // Speed of rotation

// Angle calculation based on time
float angle = ImGui::GetTime() * speed;

// Calculate x and y positions using cosine and sine
float x = centerX + radius * cos(angle);
float y = centerY + radius * sin(angle);

// Render the rotating text
draw->AddText(NULL, 20.0f, {x, y}, IM_COL32(255, 255, 0, 255), "@NedexG");


if (Config.OTHER.HIDEESP) {
        HIDEESP = false;
    } else {
        HIDEESP = true;
    }
    if (HIDEESP) {

        auto Actors = getActors();

        int totalEnemies = 0, totalBots = 0;

        ASTExtraPlayerCharacter *localPlayer = 0;
        ASTExtraPlayerController *localController = 0;


        std::string sFPS = "";
        sFPS += std::to_string(fps.get());

          


        for (int i = 0; i < Actors.size(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalid(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerController::StaticClass())) {
                localController = (ASTExtraPlayerController *) Actor;
                break;
            }
        }
		

		
		if (localController ==0){
			draw->AddText({((float) density / 10.0f), 40},IM_COL32(255, 0, 0, 0),sFPS.c_str());
			}else{
            std::string sFPS = "";
            sFPS += std::to_string(fps.get());
            draw->AddText({((float) density / 10.0f), 40},IM_COL32(255, 155, 0, 0),sFPS.c_str());
        }

        if (localController) {
            for (int i = 0; i < Actors.size(); i++) {
                auto Actor = Actors[i];
                if (isObjectInvalid(Actor))
                    continue;

                if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                    if (((ASTExtraPlayerCharacter *) Actor)->PlayerKey ==
                        localController->PlayerKey) {
                        localPlayer = (ASTExtraPlayerCharacter *) Actor;
                        break;
                    }
                }
            }


                            if (localPlayer) {
								
								
								if (localPlayer->PartHitComponent) {
    auto ConfigCollisionDistSqAngles = localPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
    int numAngles = ConfigCollisionDistSqAngles.Num();

    for (int j = numAngles - 1; j >= 0; j--) {
        int modifiedIndex = numAngles - j - 1;
        float offset = sin(j * 0.2f + 0.3f) * 30.0f; 
        float baseAngle = modifiedIndex % 2 == 0 ? 170.0f : -190.0f; 
        ConfigCollisionDistSqAngles[j].Angle = baseAngle + offset;
    }
    localPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
}
								
             if (Config.HighRisk.Recoil || Config.HighRisk.Shake || Config.HighRisk.Instant) {
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                if (WeaponManagerComponent) {
                    auto Slot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                    if ((int) Slot.GetValue() >= 1 && (int) Slot.GetValue() <= 3) {
                        auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                        if (CurrentWeaponReplicated) {
                            auto ShootWeaponEntityComp = CurrentWeaponReplicated->ShootWeaponEntityComp;
                            auto ShootWeaponEffectComp = CurrentWeaponReplicated->ShootWeaponEffectComp;
                            if (ShootWeaponEntityComp && ShootWeaponEffectComp) {

                                auto infinity = std::numeric_limits<float>::infinity();
                                auto max = std::numeric_limits<uint32_t>::max();
                                if (Config.HighRisk.Recoil) {
                                     memset(&ShootWeaponEntityComp->RecoilInfo, 0,
                                           sizeof(FSRecoilInfo));

                                    ShootWeaponEntityComp->RecoilKickADS = 0.0f;
                                }

                                if (Config.HighRisk.Shake) {
                                    ShootWeaponEntityComp->AnimationKick = 0.0f;
                                }

                                
                                }
                                }
                                }
                                }
								}


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\

                static bool bShooting = false;
			

						if (Config.SilentAim.Enable) {
                    auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                    if (WeaponManagerComponent) {
                        auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                        if ((int) propSlot.GetValue() >= 1 && (int) propSlot.GetValue() <= 3) {
                            auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                            if (CurrentWeaponReplicated) {
                                auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
								
								
                                if (ShootWeaponComponent) {
									
									
									
                                    
    int shoot_event_idx = 168; 
	
	
auto VTable = (void **) ShootWeaponComponent->VTable;

auto f_mprotect = [](uintptr_t addr, size_t len, int32_t prot) -> int32_t {
  static_assert(PAGE_SIZE == 4096);
  constexpr size_t page_size = static_cast<size_t>(PAGE_SIZE);
  void* start = reinterpret_cast<void*>(addr & -page_size);
  uintptr_t end = (addr + len + page_size - 1) & -page_size;
  
  return mprotect(start, end - reinterpret_cast<uintptr_t>(start), prot);
};

if (VTable) {
    uintptr_t table_entry = (uintptr_t)&VTable[shoot_event_idx];
    
    if (VTable[shoot_event_idx] != shoot_event) {
        orig_shoot_event = decltype(orig_shoot_event)(VTable[shoot_event_idx]);
        
        f_mprotect(table_entry, sizeof(uintptr_t), PROT_READ | PROT_WRITE);
        
        uintptr_t new_func_ptr = reinterpret_cast<uintptr_t>(&shoot_event);
        VTable[shoot_event_idx] = reinterpret_cast<void*>(new_func_ptr);
        
        f_mprotect(table_entry, sizeof(uintptr_t), PROT_READ | PROT_EXEC);
    }
}

}
}
}
}
}



						
	if (Config.PlayerESP.AutoFire) {
  if (GetTargetByPussy()) {
    localController->bIsPressingFireBtn = true;
    
  } else {
   
    qwcifqvs86y8fify = true;
    
  }
}
		/*
						
                //Aimbot//
                if (Config.AimBot.Enable) {
draw->AddCircle(ImVec2(glWidth / 2, glHeight / 2), FOVSizea, IM_COL32(255, 255, 0, 240), 0, 0.7f);;
                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                    if (Target) {
                        bool triggerOk = false;
                        if (Config.AimBot.Trigger != EAimTrigger::None) {
                            if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
                                triggerOk = localPlayer->bIsWeaponFiring;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
                                triggerOk = localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Both) {
                                triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Any) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                            }
                        } else triggerOk = true;
                        if (triggerOk) {
                            FVector targetAimPos = Target->GetBonePos("Head", {});
                            if (Config.AimBot.Target == EAimTarget::Chest) {
                                targetAimPos.Z -= 25.0f;
                            }

                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                            if (WeaponManagerComponent) {
                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                if ((int) propSlot.GetValue() >= 1 &&
                                    (int) propSlot.GetValue() <= 3) {
                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                    if (CurrentWeaponReplicated) {
                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                        if (ShootWeaponComponent) {
                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                            if (ShootWeaponEntityComponent) {
                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                if (CurrentVehicle) {
                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;

                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;

                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    LinearVelocity, timeToTravel));
                                                } else {
                                                    FVector Velocity = Target->GetVelocity();

                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;

                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    Velocity, timeToTravel));
                                                }
                                                localController->SetControlRotation(ToRotator(
                                                        localController->PlayerCameraManager->CameraCache.POV.Location,
                                                        targetAimPos), "");
														
                                            if (Config.AimBot.RecoilComparison) {
                                                    if (g_LocalPlayer->bIsGunADS) {
                                                        if (g_LocalPlayer->bIsWeaponFiring) {
                                                            float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
                                                            targetAimPos.Z -= dist * Config.AimBot.Recc;
                                                        }  
                                                    }
                                                }
                                                
                                                
                                                
                                                
FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_LocalController->PlayerCameraManager->CameraCache.POV.Location);
                                            FRotator Yaptr = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                                            FRotator CpYaT = localController->PlayerCameraManager->CameraCache.POV.Rotation;
                                            Yaptr.Pitch -= CpYaT.Pitch;
                                            Yaptr.Yaw -= CpYaT.Yaw;
                                            Yaptr.Roll = 0.f;
                                            AimBotS(Yaptr);
                                            CpYaT.Pitch += Yaptr.Pitch / AimSmooth; //AIMSPEED HORIZON
                                            CpYaT.Yaw += Yaptr.Yaw / AimSmooth; // AIMSPEED VERTICAL
                                            CpYaT.Roll = 0.f;
                                            localController->SetControlRotation(CpYaT,"");
                                            }}}}}}}}
                                            
                                                /*
                                                
                                                localController->SetControlRotation(ToRotator(localController->PlayerCameraManager->CameraCache.POV.Location, targetAimPos), "");
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                  }*/
                  
                  
                  	if (Config.AimBot.Enable) {
draw->AddCircle(ImVec2(glWidth / 2, glHeight / 2), FOVSizea, IM_COL32(255, 255, 0, 240), 0, 2.0f);
                    ASTExtraPlayerCharacter *Target = GetTargetForAimBot();
                    if (Target) {
                        bool triggerOk = false;
                        if (Config.AimBot.Trigger != EAimTrigger::None) {
                            if (Config.AimBot.Trigger == EAimTrigger::Shooting) {
                                triggerOk = localPlayer->bIsWeaponFiring;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Scoping) {
                                triggerOk = localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Both) {
                                triggerOk = localPlayer->bIsWeaponFiring && localPlayer->bIsGunADS;
                            } else if (Config.AimBot.Trigger == EAimTrigger::Any) {
                                triggerOk = localPlayer->bIsWeaponFiring || localPlayer->bIsGunADS;
                            }
                        } else triggerOk = true;
                        if (triggerOk){
					FVector targetAimPos = Target->GetBonePos("Head", {});
					if (Config.AimBot.Target == EAimTarget::Chest){
						targetAimPos.Z -= 29.55f;
    				targetAimPos.Y -= 1.224f;}
					
                            auto WeaponManagerComponent = localPlayer->WeaponManagerComponent;
                            if (WeaponManagerComponent) {
                                auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
                                if ((int) propSlot.GetValue() >= 1 &&
                                    (int) propSlot.GetValue() <= 3) {
                                    auto CurrentWeaponReplicated = (ASTExtraShootWeapon *) WeaponManagerComponent->CurrentWeaponReplicated;
                                    if (CurrentWeaponReplicated) {
                                        auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
                                        if (ShootWeaponComponent) {
                                            UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
                                            if (ShootWeaponEntityComponent) {
                                                ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
                                                if (CurrentVehicle) {
                                                    FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;
                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    LinearVelocity, timeToTravel));
                                                } else {
                                                    FVector Velocity = Target->GetVelocity();
                                                    float dist = localPlayer->GetDistanceTo(Target);
                                                    auto timeToTravel = dist /
                                                                        ShootWeaponEntityComponent->BulletFireSpeed;
                                                    targetAimPos = UKismetMathLibrary::Add_VectorVector(
                                                            targetAimPos,
                                                            UKismetMathLibrary::Multiply_VectorFloat(
                                                                    Velocity, timeToTravel));}
							if (Config.AimBot.RecoilComparison) {
        if (g_LocalPlayer->bIsGunADS) {
        if (g_LocalPlayer->bIsWeaponFiring) {
        float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;                                                                                 
        targetAimPos.Z -= dist * Config.AimBot.Recc;}}}
                                                FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_LocalController->PlayerCameraManager->CameraCache.POV.Location);
                                            FRotator Yaptr = UKismetMathLibrary::Conv_VectorToRotator(fDir);
                                            FRotator CpYaT = localController->PlayerCameraManager->CameraCache.POV.Rotation;
                                            Yaptr.Pitch -= CpYaT.Pitch;
                                            Yaptr.Yaw -= CpYaT.Yaw;
                                            Yaptr.Roll = 0.f;
                                            AimBotS(Yaptr);
                                            CpYaT.Pitch += Yaptr.Pitch / AimSmooth; //AIMSPEED HORIZON
                                            CpYaT.Yaw += Yaptr.Yaw / AimSmooth; // AIMSPEED VERTICAL
                                            CpYaT.Roll = 0.f;
                                            localController->SetControlRotation(CpYaT,"");
                                            }}}}}}}}			
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\


                for (auto &i : Actors) {
                auto Actor = i;
                if (isObjectInvalid(Actor))
                    continue;

                if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                    auto Player = (ASTExtraPlayerCharacter *) Actor;
/*ImU32 PlayerBone;
                            ImU32 PlayerLine;
                            ImU32 BotLine;
                            ImU32 BotBone;
                            ImU32 PlayerAlert;
                            ImU32 BotAlert;*/
                    float Distance = localPlayer->GetDistanceTo(Player) / 100.0f;
                    if (Distance > 500)
                        continue;

                    if (Player->PlayerKey == localController->PlayerKey)
                        continue;

                    if (Player->TeamID == localController->TeamID)
                        continue;

                    if (Player->bDead)
                        continue;

                   /* if (!Player->Mesh)
                        continue;*/

                    if (Player->bEnsure)
                        totalBots++;
                    else totalEnemies++;

                    if (Config.PlayerESP.NoBot)
                        if (Player->bEnsure)
                            continue;

                    float magic_number = (Distance);
                    float mx = (glWidth / 4) / magic_number;

                    float healthLength = glWidth / 19;
                    if (healthLength < mx)
                        healthLength = mx;

                    auto HeadPos = Player->GetBonePos("Head", {});
                    ImVec2 HeadPosSC;

                    auto RootPos = Player->GetBonePos("Root", {});
                    ImVec2 RootPosSC;
                    auto upper_r = Player->GetBonePos("upperarm_r", {});
                    ImVec2 upper_rPoSC;
                    auto lowerarm_r = Player->GetBonePos("lowerarm_r", {});
                    ImVec2 lowerarm_rPoSC;
                    auto hand_r = Player->GetBonePos("hand_r", {});
                    ImVec2 hand_rPoSC;
                    auto upper_l = Player->GetBonePos("upperarm_l", {});
                    ImVec2 upper_lPoSC;
                    auto lowerarm_l = Player->GetBonePos("lowerarm_l", {});
                    ImVec2 lowerarm_lSC;
                    auto hand_l = Player->GetBonePos("hand_l", {});
                    ImVec2 hand_lPoSC;
                    auto thigh_l = Player->GetBonePos("thigh_l", {});
                    ImVec2 thigh_lPoSC;
                    auto calf_l = Player->GetBonePos("calf_l", {});
                    ImVec2 calf_lPoSC;
                    auto foot_l = Player->GetBonePos("foot_l", {});
                    ImVec2 foot_lPoSC;
                    auto thigh_r = Player->GetBonePos("thigh_r", {});
                    ImVec2 thigh_rPoSC;
                    auto calf_r = Player->GetBonePos("calf_r", {});
                    ImVec2 calf_rPoSC;
                    auto foot_r = Player->GetBonePos("foot_r", {});
                    ImVec2 foot_rPoSC;
                    auto neck_01 = Player->GetBonePos("neck_01", {});
                    ImVec2 neck_01PoSC;
                    auto pelvis = Player->GetBonePos("pelvis", {});
                    ImVec2 pelvisPoSC;
                    
                    
       long SCOLOR2 = IM_COL32(245, 233, 0, 255); 
                            long SCOLORA = IM_COL32(255, 0, 0, 255);
                            long SCOLOR = IM_COL32(0, 255, 0, 255);
                            long SCOLOR1 = IM_COL32(255, 255, 255, 255);
                            
                            long PlayerBoxClrCf = IM_COL32(255, 255, 255, 150);
                            long PlayerBoxClrCfline = IM_COL32(255, 255, 255, 255);
                            long PlayerBoxClrCfbx = IM_COL32(255, 255, 255, 255);
                        
                            if (!localController->LineOfSightTo(Player, {0, 0, 0}, true)) {
                            
                            SCOLORA = IM_COL32(10, 250, 250, 255); 
                            SCOLOR2 = IM_COL32(23, 250, 15, 255); 
                            SCOLOR = IM_COL32(10, 250, 250, 255); 
                            SCOLOR = IM_COL32(10, 250, 250, 255); 
                            SCOLOR1 = IM_COL32(10, 250, 250, 255); 
                            
                            PlayerBoxClrCf = IM_COL32(0, 255, 0, 150);
                            PlayerBoxClrCfline = IM_COL32(0, 255, 0, 255);
                            PlayerBoxClrCfbx = IM_COL32(0, 255, 0, 255);
                            
                            }
                            
                            
                    bool IsVisible = localController->LineOfSightTo(Player, {0, 0, 0}, true);

                   // int SCOLOR, SCOLOR2;

                   
         /*          
                   int Colorhealth;
                                        int healthOutline;                                                                         
                                                  if (Player->bEnsure){
                                            totalBots++;
                                            Colorhealth = IM_COL32(255, 000, 000, 170);
                                            healthOutline = IM_COL32(255, 000, 000, 170);
                                            }else{
                                            totalEnemies++;
                                            Colorhealth = IM_COL32(000, 255, 000, 170);
                                            healthOutline = IM_COL32(000, 255, 000, 170);           
                                            }
                   
                   
                                                                                               
                                                                            
                            if (IsVisible) {
                                //OPN 
                                BotBone = IM_COL32(0, 255, 0, 255);
                                PlayerBone = IM_COL32(182, 242, 89, 255);
                                PlayerLine = IM_COL32(182, 242, 89, 255);
                                BotLine = IM_COL32(182, 242, 89, 255);
                            } else {
                                //COBR
                                BotBone = IM_COL32(255, 255, 0, 255);
                                PlayerBone = IM_COL32(255, 255, 0, 255);
                                PlayerLine = IM_COL32(255, 255, 0, 255);
                                BotLine = IM_COL32(255, 255, 0, 255);
                            }
         */
                                            
                                            
					if (Player->bEnsure) {
                        CounterColorByAYAN = IM_COL32(155, 4, 219, 255);
                    }else{
                        CounterColorByAYAN = IM_COL32(255, 0, 0, 255);
                    }
					/*
                    if (Player->bEnsure) {
                        SCOLOR2 = IM_COL32(155, 4, 219, 255);
                    }else{
                        SCOLOR2 = IM_COL32(255, 255, 0, 255);
                    }
*/
                    if (W2S(HeadPos, (FVector2D *) &HeadPosSC) &&
                        W2S(upper_r, (FVector2D *) &upper_rPoSC) &&
                        W2S(upper_l, (FVector2D *) &upper_lPoSC) &&
                        W2S(lowerarm_r, (FVector2D *) &lowerarm_rPoSC ) &&
                        W2S(hand_r, (FVector2D *) &hand_rPoSC ) &&
                        W2S(lowerarm_l, (FVector2D *) &lowerarm_lSC ) &&
                        W2S(hand_l, (FVector2D *) &hand_lPoSC ) &&
                        W2S(thigh_l, (FVector2D *) &thigh_lPoSC ) &&
                        W2S(calf_l, (FVector2D *) &calf_lPoSC ) &&
                        W2S(foot_l, (FVector2D *) &foot_lPoSC ) &&
                        W2S(thigh_r, (FVector2D *) &thigh_rPoSC ) &&
                        W2S(calf_r, (FVector2D *) &calf_rPoSC ) &&
                        W2S(foot_r, (FVector2D *) &foot_rPoSC ) &&
                        W2S(neck_01, (FVector2D *) &neck_01PoSC ) &&
                        W2S(pelvis, (FVector2D *) &pelvisPoSC ) &&
                        W2S(RootPos, (FVector2D *) &RootPosSC)){

                             if (Config.PlayerESP.Line) { 		// MADE BY @NHKMOD 
                                    draw->AddLine({(float) glWidth / 2, 70}, ImVec2(HeadPosSC.x, HeadPosSC.y - 30.0f),
                                                  SCOLOR2, 0.6f);	// MADE BY @NHKMOD 
                                }
                              if (Config.PlayerESP.Box) {
                                float boxHeight = abs(HeadPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2), HeadPosSC.y};
                                    ImVec2 vEnd = {vStart.x + boxWidth, vStart.y + boxHeight};

                                    draw->AddRect(vStart, vEnd, SCOLOR, 0.0f, 240, 1.2f);
									
									auto tpColor = ImColor(255, 255, 255,30);
                                    auto bttomColor = ImColor(0, 175, 239, 30);
                                    auto tpoColor = ImColor(255, 0, 0,30);
                                    auto btotomColor = ImColor(255, 255, 255,30);
									draw->AddRectFilledMultiColor(vStart, vEnd, tpColor, tpoColor, btotomColor, bttomColor);

									}
									
                            if (Config.PlayerESP.Skeleton) {
                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, neck_01PoSC, SCOLOR2, 1.5f);
                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, neck_01PoSC, SCOLOR2, 1.5f);

                                draw->AddLine({upper_rPoSC.x, upper_rPoSC.y}, lowerarm_rPoSC, SCOLOR2, 1.5f);
                                draw->AddLine({lowerarm_rPoSC.x, lowerarm_rPoSC.y}, hand_rPoSC, SCOLOR2 , 1.5f);

                                draw->AddLine({upper_lPoSC.x, upper_lPoSC.y}, lowerarm_lSC, SCOLOR2, 1.5f);
                                draw->AddLine({lowerarm_lSC.x, lowerarm_lSC.y}, hand_lPoSC, SCOLOR2, 1.5f);

                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, thigh_lPoSC, SCOLOR2, 1.5f);

                                draw->AddLine({thigh_lPoSC.x, thigh_lPoSC.y}, calf_lPoSC, SCOLOR2, 1.5f);
                                draw->AddLine({calf_lPoSC.x, calf_lPoSC.y}, foot_lPoSC, SCOLOR2, 1.5f);

                                draw->AddLine({thigh_rPoSC.x, thigh_rPoSC.y}, calf_rPoSC, SCOLOR2, 1.5f);
                                draw->AddLine({calf_rPoSC.x, calf_rPoSC.y}, foot_rPoSC, SCOLOR2, 1.5f);

                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, pelvisPoSC, SCOLOR2, 1.5f);
                                draw->AddLine({neck_01PoSC.x, neck_01PoSC.y}, HeadPosSC, SCOLOR2, 1.5f);

								}
                                
                                
       /*
if (Config.PlayerESP.Health) {
    int CurHP = (Player->Health < 0) ? 0 : (Player->Health > 100) ? 100 : Player->Health;
    int MaxHP = 100;
    long HPColor;

    if (Player->Health < 25) {
        HPColor = IM_COL32(220, 255, 0, 100);
    } else if (Player->Health < 50) {
        HPColor = IM_COL32(220, 255, 0, 100);
    } else if (Player->Health < 75) {
        HPColor = IM_COL32(220, 255, 0, 100);
    } else {
        HPColor = Colorhealth;
    }

    if (Player->Health == 0.0f && !Player->bDead) {
        HPColor = IM_COL32(255, 255, 0, 255);
        HPColor = IM_COL32(220, 255, 0, 55);

        CurHP = (Player->NearDeathBreath < 0) ? 0 : (Player->NearDeathBreath > 100) ? 100 : Player->NearDeathBreath;

        if (Player->NearDeatchComponent) {
            MaxHP = 100;
        }
    }

    float boxWidth = density / 1.6f;
    boxWidth -= std::min(((boxWidth / 2) / 0.001f) * Distance, boxWidth / 2);
    float boxHeight = boxWidth * 0.15f;

    ImVec2 vStart = {HeadPosSC.x - (boxWidth / 2), HeadPosSC.y - (boxHeight * 2.001f)};
    ImVec2 vEndFilled = {vStart.x + (CurHP * boxWidth / MaxHP), vStart.y + boxHeight};
    ImVec2 vEndRect = {vStart.x + boxWidth, vStart.y + boxHeight};

    draw->AddRectFilledMultiColor(vStart, vEndFilled, IM_COL32(220, 255, 0, 155), HPColor, HPColor, IM_COL32(220, 255, 0, 155));
    draw->AddRect(vStart, vEndRect, healthOutline, 1.0f);


                            }
                            
                            
      if (Config.PlayerESP.Name) {
    float boxWidth = density / 1.6f;
    boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance, boxWidth / 2);
    float boxHeight = boxWidth * 0.15f;

    std::string s = Player->bEnsure ? "      BOT" : Player->PlayerName.ToString();

    draw->AddText(NULL, density / 30.0f,
                  {HeadPosSC.x - boxWidth / 3.5f, HeadPosSC.y - boxHeight * 1.83f},
                  IM_COL32(255, 255, 255, 255), s.c_str());
}

if (Config.PlayerESP.TeamID) {
    float boxWidth = density / 1.6f;
    boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance, boxWidth / 2);
    float boxHeight = boxWidth * 0.15f;

    std::string s = std::to_string(Player->TeamID);

    draw->AddText(NULL, density / 30.0f,
                  {HeadPosSC.x - boxWidth / 2.3f, HeadPosSC.y - boxHeight * 1.83f},
                  IM_COL32(255, 255, 255, 255), s.c_str());
}

if (Config.PlayerESP.Distance) {
    float boxWidth = density / 1.6f;
    boxWidth -= std::min(((boxWidth / 2) / 00.0f) * Distance,boxWidth / 2);
    float boxHeight = boxWidth * 0.15f;
    std::string s = "  " + std::to_string((int)Distance) + "M";
    draw->AddText(NULL, ((float)density / 30.0f), {HeadPosSC.x + (boxWidth / 5.5f), HeadPosSC.y - (boxHeight * 1.83f)}, IM_COL32(255, 255, 255, 255), s.c_str());
}                              
}}*/

                                
                                
                                
                                
                                
                                
                                
								
				                if (Config.PlayerESP.Health || Config.PlayerESP.Name || Config.PlayerESP.TeamID) {
                          //      draw->AddRectFilled({HeadPosSC.x - 95, HeadPosSC.y - 58}, {HeadPosSC.x + 80,HeadPosSC.y - 29}, GetRandomColorByIndex(Player->TeamID), 1, 0);
						   	    }
				
                            if (Config.PlayerESP.Health) { 				
                            long HPColor;
								int CurHP = (int) std::max(0, std::min((int) Player->Health,100));
                                int MaxHP = 100;
                                long Fuck = IM_COL32(0, 255, 0, 240);
                                draw->AddRectFilled({HeadPosSC.x - 95, HeadPosSC.y - 26 - 7 }, {HeadPosSC.x - 110 + (1.9 * CurHP), HeadPosSC.y - 29.2},Fuck, 1, 0);
                          
                          if (Player->Health == 0.0f && !Player->bDead) {
    HPColor = IM_COL32(252, 3, 3, 255);  // Purple for knocked state
    CurHP = (int) std::max(0, std::min((int) Player->NearDeathBreath, 100));
    if (Player->NearDeatchComponent) {
        MaxHP = 100; // Set max HP for knocked state
    }
}
   }                       
                          
                                   /*   if (Player->Health == 0.0f && !Player->bDead) {
                                CurHP = Player->NearDeathBreath;
                                if (Player->NearDeatchComponent) {
                                MaxHP = 100;// Player->NearDeatchComponent->BreathMax;
								}}}*/


                            if (Config.PlayerESP.TeamID) { 								
								std::string s;
								auto textSize = ImGui::CalcTextSize(s.c_str(), 0);     
								if(Player->TeamID < 10 ){
								s +=" 0";
								s += std::to_string(Player->TeamID);
								draw->AddText(NHKModFont ,15,ImVec2(HeadPosSC.x - 92  - 1 - (textSize.x / 2), HeadPosSC.y - 60.5 + 9), IM_COL32(255, 255, 255, 255),s.c_str());
								}
								else if(Player->TeamID < 100){
								s+=" ";
								s += std::to_string(Player->TeamID);
								draw->AddText(NHKModFont ,15 ,ImVec2(HeadPosSC.x - 91 - (textSize.x / 2), HeadPosSC.y - 60.5 + 9), IM_COL32(255, 255, 255, 255),s.c_str());								  
								}	else {
								s += std::to_string(Player->TeamID);
								draw->AddText(NHKModFont ,15,ImVec2(HeadPosSC.x - 92  - 1 - (textSize.x / 2), HeadPosSC.y - 60.5 + 9), IM_COL32(255, 255, 255, 255),s.c_str());
				                }}
                         	
							     if (Config.PlayerESP.Name) {					
   					            std::string s;                              					
	                  	        if (Player->bEnsure) {								
	                           	s += " ";                               							
		                        s += "Bot";                           
                            	} else {                      
	                            s += Player->PlayerName.ToString();      	
	                            }
                                draw->AddText(NHKModFont,15.f,ImVec2(HeadPosSC.x - 50 - 6, HeadPosSC.y - 55.9 + 4), IM_COL32(255, 255, 255, 255),s.c_str());
				            	}             
								
						         if (Config.PlayerESP.Distance) {
                                    float boxHeight = abs(HeadPosSC.y - RootPosSC.y);
                                    float boxWidth = boxHeight * 0.65f;
                                    std::string s;
                                    if (Config.PlayerESP.Distance) {
                                        if (!s.empty()) {
                                            s += " ";
                                        }
                                        s += std::to_string((int) Distance);
                                        s += "M";
                                    }
								auto textSize = ImGui::CalcTextSize(s.c_str(), 0);     
								draw->AddText(NHKModFont ,15,ImVec2(HeadPosSC.x - 92  + 164 - (textSize.x / 2), HeadPosSC.y - 60.5 + 9), IM_COL32(255, 255, 255, 255),s.c_str());
                                }
                            }
                         }
						 
						 if (Config.PlayerESP.Grenade) {
                      if (Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
                            auto Grenade = (ASTExtraGrenadeBase *) Actor;

                            auto RootComponent = Grenade->RootComponent;
                            if (!RootComponent)
                                continue;
                            float Distance = Grenade->GetDistanceTo(localPlayer) / 70.f;
                            FVector2D grenadePos;
                            if (W2S(Grenade->K2_GetActorLocation(), &grenadePos)) {
                                 std::string s = "Grenade";
                                 s += " - ";
                                 s += std::to_string((int) Distance);
                                 s += " m";
                                 draw->AddText(NHKModFont, ((float) density / 26.0f),
                                                  {grenadePos.X, grenadePos.Y},
                                                  IM_COL32(255, 255, 0, 255), s.c_str());
                                }
                        }
                    }
				
	                        if (Config.PlayerESP.LootBox) {
                            if (Actor->IsA(APickUpListWrapperActor::StaticClass())) {
                                auto LootBox = (APickUpListWrapperActor *) Actor;
                                auto RootComponent = Actor->RootComponent;
                                if (!RootComponent)
                                    continue;
                                float Distance = LootBox->GetDistanceTo(localPlayer) / 100.f;

                                FVector2D lootboxPos;
                                if (W2S(LootBox->K2_GetActorLocation(), &lootboxPos)) {
                                    std::string s = "LootBox";
                                    s += " - ";
                                    s += std::to_string((int) Distance);
                                    s += "m";

                                    draw->AddText(Ayanfont, ((float) density / 26.0f),
                                                  {lootboxPos.X, lootboxPos.Y},
                                                  IM_COL32(0, 255, 255, 255), s.c_str());
                                }
                            }
                        }



                if (Config.PlayerESP.Vehicle) {
                    if (i->IsA(ASTExtraVehicleBase::StaticClass())) {
                        auto Vehicle = (ASTExtraVehicleBase *) i;

                        if (!Vehicle->Mesh)
                            continue;

                        float Distance = Vehicle->GetDistanceTo(localPlayer) / 100.f;

                        FVector2D vehiclePos;
                        if (W2S(Vehicle->K2_GetActorLocation(), &vehiclePos)) {
                            std::string s = "";
                                s += GetVehicleName(Vehicle);
                            s += " - ";
                                s += std::to_string((int) Distance);
                                s += "m";

                            draw->AddText(Ayanfont, ((float) density / 20.0f), {vehiclePos.X, vehiclePos.Y}, IM_COL32(255, 255, 0, 255), s.c_str());
                        }
                    }
                }

			
                if (i->IsA(APickUpWrapperActor::StaticClass())) {
                    auto PickUp = (APickUpWrapperActor *) i;
                    if (Items[PickUp->DefineID.TypeSpecificID]) {
                        auto RootComponent = PickUp->RootComponent;
                        if (!RootComponent)
                            continue;

                        float Distance = PickUp->GetDistanceTo(localPlayer) / 100.f;

                        FVector2D itemPos;
                            if (W2S(PickUp->K2_GetActorLocation(), &itemPos)) {
                                std::string s;
                                uint32_t tc = 0xFF000000;

                                for (auto &category: items_data) {
                                    for (auto &item: category["Items"]) {
                                        if (item["itemId"] == PickUp->DefineID.TypeSpecificID) {
                                            s = item["itemName"].get<std::string>();
                                            tc = strtoul(
                                                    item["itemTextColor"].get<std::string>().c_str(),
                                                    0, 16);
                                            break;
                                    }
                                }
                            }

                            s += " - ";
                            s += std::to_string((int) Distance);
                            s += "M]";
							
							draw->AddText(NULL, ((float) density / 20.0f),
                                              {itemPos.X, itemPos.Y}, tc, s.c_str());
                        }
                    }
                }
            }
        }
    }
	
	
	
g_LocalController = localController;
g_LocalPlayer = localPlayer;
    std::string s;
if (totalEnemies > 0 || totalBots > 0){
ImVec2 center = ImGui::GetMainViewport()->GetCenter();
    ImGui::SetNextWindowPos(ImVec2(center.x, 100), ImGuiCond_FirstUseEver, ImVec2(0.5f, 0.5f));
    ImGui::SetNextWindowSize(ImVec2(280.0f, 30.0f)); // Smaller size for the box

    ImGui::Begin("Null", nullptr, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoScrollbar | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings);

    ImVec2 windowSizeActual = ImGui::GetWindowSize();

    // Center the text within the fixed size window
    float textPosX = (windowSizeActual.x - ImGui::CalcTextSize("Players: 0 Bots: 0").x) / 2.0f;
    float textPosY = (windowSizeActual.y - ImGui::CalcTextSize("Players: 0 Bots: 0").y) / 2.0f;

    ImGui::SetCursorPos(ImVec2(textPosX, textPosY));
    ImGui::Text("Players: %d  Bots: %d", totalEnemies, totalBots);
                




/*
    s += " E ";
    s += std::to_string(totalEnemies);
    s += " : ";
    s += std::to_string(totalBots);
    s += " B";
    
    float new_height = 23;
    float new_width = 143;

    float x1 = glWidth / 2 - new_width / 2;
    float y1 = 70;
    float x2 = glWidth / 2 + new_width / 2;
    float y2 = y1 + new_height;
    
    if (totalEnemies == 0){
    draw->AddRectFilled(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(155, 4, 219, 255), 0.0f);
	} else {
    draw->AddRectFilled(ImVec2(x1, y1), ImVec2(x2, y2), IM_COL32(255, 0, 0, 255), 0.0f);
	}
    
    
  draw->AddText(NHKModFont, ((float)density / 18.5f), ImVec2(x1 + 9 - 8, y1 + 5 - 5), IM_COL32(255, 255, 255, 255), s.c_str());
  
  */
    }
}
}


// DM BUY PRIVATE SOURCE  @DEVILHACKYT 
// TELEGRAM https://t.me/+drKaQFZMeuQ3OThl
// main channel https://t.me/+vEhRUxREo-oxMzhl
// Join Our Bypass Chennal https://t.me/+cICpy0QfzVAyNDY1

 
    std::string getClipboardText() {
        if (!g_App)
            return "";

        auto activity = g_App->activity;
        if (!activity)
            return "";

        auto vm = activity->vm;
        if (!vm)
            return "";

        auto object = activity->clazz;
        if (!object)
            return "";

        std::string result;

        JNIEnv *env;
        vm->AttachCurrentThread(&env, 0);
        {
            auto ContextClass = env->FindClass("android/content/Context");
            auto getSystemServiceMethod = env->GetMethodID(ContextClass, "getSystemService", "(Ljava/lang/String;)Ljava/lang/Object;");

            auto str = env->NewStringUTF("clipboard");
            auto clipboardManager = env->CallObjectMethod(object, getSystemServiceMethod, str);
            env->DeleteLocalRef(str);

            auto ClipboardManagerClass = env->FindClass("android/content/ClipboardManager");
            auto getText = env->GetMethodID(ClipboardManagerClass, "getText", "()Ljava/lang/CharSequence;");

            auto CharSequenceClass = env->FindClass("java/lang/CharSequence");
            auto toStringMethod = env->GetMethodID(CharSequenceClass, "toString", "()Ljava/lang/String;");

            auto text = env->CallObjectMethod(clipboardManager, getText);
            if (text) {
                str = (jstring) env->CallObjectMethod(text, toStringMethod);
                result = env->GetStringUTFChars(str, 0);
                env->DeleteLocalRef(str);
                env->DeleteLocalRef(text);
            }

            env->DeleteLocalRef(CharSequenceClass);
            env->DeleteLocalRef(ClipboardManagerClass);
            env->DeleteLocalRef(clipboardManager);
            env->DeleteLocalRef(ContextClass);
        }
        vm->DetachCurrentThread();

        return result;
    }

		// NHK MOD
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
		// NHK MOD
    const char *GetAndroidID(JNIEnv *env, jobject context) {
        jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
        jmethodID getContentResolverMethod = env->GetMethodID(contextClass, /*getContentResolver*/ StrEnc("E8X\\7r7ys_Q%JS+L+~", "\x22\x5D\x2C\x1F\x58\x1C\x43\x1C\x1D\x2B\x03\x40\x39\x3C\x47\x3A\x4E\x0C", 18).c_str(), /*()Landroid/content/ContentResolver;*/ StrEnc("8^QKmj< }5D:9q7f.BXkef]A*GYLNg}B!/L", "\x10\x77\x1D\x2A\x03\x0E\x4E\x4F\x14\x51\x6B\x59\x56\x1F\x43\x03\x40\x36\x77\x28\x0A\x08\x29\x24\x44\x33\x0B\x29\x3D\x08\x11\x34\x44\x5D\x77", 35).c_str());
        jclass settingSecureClass = env->FindClass(/*android/provider/Settings$Secure*/ StrEnc("T1yw^BCF^af&dB_@Raf}\\FS,zT~L(3Z\"", "\x35\x5F\x1D\x05\x31\x2B\x27\x69\x2E\x13\x09\x50\x0D\x26\x3A\x32\x7D\x32\x03\x09\x28\x2F\x3D\x4B\x09\x70\x2D\x29\x4B\x46\x28\x47", 32).c_str());
        jmethodID getStringMethod = env->GetStaticMethodID(settingSecureClass, /*getString*/ StrEnc("e<F*J5c0Y", "\x02\x59\x32\x79\x3E\x47\x0A\x5E\x3E", 9).c_str(), /*(Landroid/content/ContentResolver;Ljava/lang/String;)Ljava/lang/String;*/ StrEnc("$6*%R*!XO\"m18o,0S!*`uI$IW)l_/_knSdlRiO1T`2sH|Ouy__^}%Y)JsQ:-\"(2_^-$i{?H", "\x0C\x7A\x4B\x4B\x36\x58\x4E\x31\x2B\x0D\x0E\x5E\x56\x1B\x49\x5E\x27\x0E\x69\x0F\x1B\x3D\x41\x27\x23\x7B\x09\x2C\x40\x33\x1D\x0B\x21\x5F\x20\x38\x08\x39\x50\x7B\x0C\x53\x1D\x2F\x53\x1C\x01\x0B\x36\x31\x39\x46\x0C\x15\x43\x2B\x05\x30\x15\x41\x43\x46\x55\x70\x0D\x59\x56\x00\x15\x58\x73", 71).c_str());

        auto obj = env->CallObjectMethod(context, getContentResolverMethod);
        auto str = (jstring) env->CallStaticObjectMethod(settingSecureClass, getStringMethod, obj, env->NewStringUTF(/*android_id*/ StrEnc("ujHO)8OfOE", "\x14\x04\x2C\x3D\x46\x51\x2B\x39\x26\x21", 10).c_str()));
        return env->GetStringUTFChars(str, 0);
    }

    const char *GetDeviceModel(JNIEnv *env) {
        jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("m5I{GKGWBP-VOxkA", "\x0C\x5B\x2D\x09\x28\x22\x23\x78\x2D\x23\x02\x14\x3A\x11\x07\x25", 16).c_str());
        jfieldID modelId = env->GetStaticFieldID(buildClass, /*MODEL*/ StrEnc("|}[q:", "\x31\x32\x1F\x34\x76", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

        auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
        return env->GetStringUTFChars(str, 0);
    }

    const char *GetDeviceBrand(JNIEnv *env) {
        jclass buildClass = env->FindClass(/*android/os/Build*/ StrEnc("0iW=2^>0zTRB!B90", "\x51\x07\x33\x4F\x5D\x37\x5A\x1F\x15\x27\x7D\x00\x54\x2B\x55\x54", 16).c_str());
        jfieldID modelId = env->GetStaticFieldID(buildClass, /*BRAND*/ StrEnc("@{[FP", "\x02\x29\x1A\x08\x14", 5).c_str(), /*Ljava/lang/String;*/ StrEnc(".D:C:ETZ1O-Ib&^h.Y", "\x62\x2E\x5B\x35\x5B\x6A\x38\x3B\x5F\x28\x02\x1A\x16\x54\x37\x06\x49\x62", 18).c_str());

        auto str = (jstring) env->GetStaticObjectField(buildClass, modelId);
        return env->GetStringUTFChars(str, 0);
    }

    const char *GetPackageName(JNIEnv *env, jobject context) {
        jclass contextClass = env->FindClass(/*android/content/Context*/ StrEnc("`L+&0^[S+-:J^$,r9q92(as", "\x01\x22\x4F\x54\x5F\x37\x3F\x7C\x48\x42\x54\x3E\x3B\x4A\x58\x5D\x7A\x1E\x57\x46\x4D\x19\x07", 23).c_str());
        jmethodID getPackageNameId = env->GetMethodID(contextClass, /*getPackageName*/ StrEnc("YN4DaP)!{wRGN}", "\x3E\x2B\x40\x14\x00\x33\x42\x40\x1C\x12\x1C\x26\x23\x18", 14).c_str(), /*()Ljava/lang/String;*/ StrEnc("VnpibEspM(b]<s#[9cQD", "\x7E\x47\x3C\x03\x03\x33\x12\x5F\x21\x49\x0C\x3A\x13\x20\x57\x29\x50\x0D\x36\x7F", 20).c_str());

        auto str = (jstring) env->CallObjectMethod(context, getPackageNameId);
        return env->GetStringUTFChars(str, 0);
    }

    const char *GetDeviceUniqueIdentifier(JNIEnv *env, const char *uuid) {
        jclass uuidClass = env->FindClass(/*java/util/UUID*/ StrEnc("B/TxJ=3BZ_]SFx", "\x28\x4E\x22\x19\x65\x48\x47\x2B\x36\x70\x08\x06\x0F\x3C", 14).c_str());

        auto len = strlen(uuid);

        jbyteArray myJByteArray = env->NewByteArray(len);
        env->SetByteArrayRegion(myJByteArray, 0, len, (jbyte *) uuid);

        jmethodID nameUUIDFromBytesMethod = env->GetStaticMethodID(uuidClass, /*nameUUIDFromBytes*/ StrEnc("P6LV|'0#A+zQmoat,", "\x3E\x57\x21\x33\x29\x72\x79\x67\x07\x59\x15\x3C\x2F\x16\x15\x11\x5F", 17).c_str(), /*([B)Ljava/util/UUID;*/ StrEnc("sW[\"Q[W3,7@H.vT0) xB", "\x5B\x0C\x19\x0B\x1D\x31\x36\x45\x4D\x18\x35\x3C\x47\x1A\x7B\x65\x7C\x69\x3C\x79", 20).c_str());
        jmethodID toStringMethod = env->GetMethodID(uuidClass, /*toString*/ StrEnc("2~5292eW", "\x46\x11\x66\x46\x4B\x5B\x0B\x30", 8).c_str(), /*()Ljava/lang/String;*/ StrEnc("P$BMc' #j?<:myTh_*h0", "\x78\x0D\x0E\x27\x02\x51\x41\x0C\x06\x5E\x52\x5D\x42\x2A\x20\x1A\x36\x44\x0F\x0B", 20).c_str());

        auto obj = env->CallStaticObjectMethod(uuidClass, nameUUIDFromBytesMethod, myJByteArray);
        auto str = (jstring) env->CallObjectMethod(obj, toStringMethod);
        return env->GetStringUTFChars(str, 0);
    }

    struct MemoryStruct {
        char *memory;
        size_t size;
    };

    static size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        size_t realsize = size * nmemb;
        struct MemoryStruct *mem = (struct MemoryStruct *) userp;

        mem->memory = (char *) realloc(mem->memory, mem->size + realsize + 1);
        if (mem->memory == NULL) {
            return 0;
        }

        memcpy(&(mem->memory[mem->size]), contents, realsize);
        mem->size += realsize;
        mem->memory[mem->size] = 0;

        return realsize;
    }
    
    /*

    ImVec4 RainbowColor(float t)
{
    float r = 0.5f + 0.5f * sinf(2.0f * 3.14159f * t);
    float g = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.33f));
    float b = 0.5f + 0.5f * sinf(2.0f * 3.14159f * (t + 0.66f));
    return ImVec4(r, g, b, 1.0f);
}
*/
void SuperText(const char* text)
{
   
    static auto start_time = std::chrono::high_resolution_clock::now();
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::high_resolution_clock::now() - start_time
    ).count() / 1000.0f;

    for (int i = 0; i < strlen(text); ++i)
    {

        float wave_offset = sinf(elapsed_time * 2.0f + i * 0.5f) * 5.0f;

  
        float t = fmodf(elapsed_time + (float)i / (float)strlen(text), 1.0f);
        ImVec4 currentColor = RainbowColor(t);

   
        ImGui::PushStyleColor(ImGuiCol_Text, currentColor);

 
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + wave_offset);
        ImGui::Text("%c", text[i]);
        ImGui::SameLine();

        ImGui::PopStyleColor();
    }
    ImGui::NewLine();
}


    std::string Login(const char *user_key) {
    if (!g_App)
        return "Internal Error";

    auto activity = g_App->activity;
    if (!activity)
        return "Internal Error";

    auto vm = activity->vm;
    if (!vm)
        return "Internal Error";

    auto object = activity->clazz;
    if (!object)
        return "Internal Error";

    JNIEnv *env;
    vm->AttachCurrentThread(&env, 0);
    std::string hwid = user_key;
    hwid += GetAndroidID(env, object);
    hwid += GetDeviceModel(env);
    hwid += GetDeviceBrand(env);
    std::string UUID = GetDeviceUniqueIdentifier(env, hwid.c_str());
    vm->DetachCurrentThread();
    std::string errMsg;

    struct MemoryStruct chunk{};
    chunk.memory = (char *) malloc(1);
    chunk.size = 0;

    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    //======LINKURL=====//
          if (curl) {
   
     //SRC UNDETECT BY:- @AYAN_CHEATS_OWNER

//=====@AYAN_CHEATS=========@ARK_CLAN=======   
         std::string CRACKSNIPER = OBFUSCATE("https://ayanxmod.vip-api.buzz/connect") ;
        curl_easy_setopt(curl, CURLOPT_URL, CRACKSNIPER.c_str());
        
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_DEFAULT_PROTOCOL, /*https*/ StrEnc("!mLBO", "\x49\x19\x38\x32\x3C", 5).c_str());
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, /*Content-Type: application/x-www-form-urlencoded*/ StrEnc("@;Ls\\(KP4Qrop`b#d3094/r1cf<c<=H)AiiBG6i|Ta66s2[", "\x03\x54\x22\x07\x39\x46\x3F\x7D\x60\x28\x02\x0A\x4A\x40\x03\x53\x14\x5F\x59\x5A\x55\x5B\x1B\x5E\x0D\x49\x44\x4E\x4B\x4A\x3F\x04\x27\x06\x1B\x2F\x6A\x43\x1B\x10\x31\x0F\x55\x59\x17\x57\x3F", 47).c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char data[4096];
        sprintf(data, /*game=PUBG&user_key=%s&serial=%s*/ StrEnc("qu2yXK,YkJyGD@ut0.u~Nb'5(:.:chK", "\x16\x14\x5F\x1C\x65\x1B\x79\x1B\x2C\x6C\x0C\x34\x21\x32\x2A\x1F\x55\x57\x48\x5B\x3D\x44\x54\x50\x5A\x53\x4F\x56\x5E\x4D\x38", 31).c_str(), user_key, UUID.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *) &chunk);

        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

        res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                json result = json::parse(chunk.memory);
                if (result[/*status*/ StrEnc("(>_LBm", "\x5B\x4A\x3E\x38\x37\x1E", 6).c_str()] == true) {
                    std::string token = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*token*/ StrEnc("{>3Lr", "\x0F\x51\x58\x29\x1C", 5).c_str()].get<std::string>();
                    time_t rng = result[/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*rng*/ StrEnc("+n,", "\x59\x00\x4B", 3).c_str()].get<time_t>();
        //floating = result [/*data*/ StrEnc("fAVA", "\x02\x20\x22\x20", 4).c_str()][/*credit*/ StrEnc("0=Fei|", "\x53\x4F\x23\x01\x00\x08", 6).c_str()].get<std::string>();
             //       EXP = result["data"]["EXP"].get<std::string>();
             //       SLOT = result["data"]["SLOT"].get<std::string>();
            //        modname = result["data"]["modname"].get<std::string>();
            //        mod_status = result["data"]["mod_status"].get<std::string>();
           //         credit = result["data"]["credit"].get<std::string>();
              //      key = result["data"]["key"].get<std::string>();
                    if (rng + 30 > time(0)) {
                        std::string auth = /*PUBG*/ StrEnc("Q*) ", "\x01\x7F\x6B\x67", 4).c_str();;
                        auth += "-";
                        auth += user_key;
                        auth += "-";
                        auth += UUID;
                        auth += "-";
                        auth += /*Vm8Lk7Uj2JmsjCPVPVjrLa7zgfx3uz9E*/ StrEnc("-2:uwZdV^%]?{{wHs2V,+(^NJU;kC*_{", "\x7B\x5F\x02\x39\x1C\x6D\x31\x3C\x6C\x6F\x30\x4C\x11\x38\x27\x1E\x23\x64\x3C\x5E\x67\x49\x69\x34\x2D\x33\x43\x58\x36\x50\x66\x3E", 32).c_str();
                        std::string outputAuth = Tools::CalcMD5(auth);
     
                        g_Token = token;
                        g_Auth = outputAuth;
                
                        bValid = g_Token == g_Auth;
                    expiredDate = result["data"]["expiredDate"].get<std::string>();
                        mod_status = result ["data"]["mod_status"];
                        device = result ["data"]["device"];
                        floting = result ["data"]["_ftext"];
                        modname = result ["data"]["modname"];
                    }
                } else {
                    errMsg = result[/*reason*/ StrEnc("LW(3(c", "\x3E\x32\x49\x40\x47\x0D", 6).c_str()].get<std::string>();
                }
            } catch (json::exception &e) {
                errMsg = "{";
                errMsg += e.what();
                errMsg += "}\n{";
                errMsg += chunk.memory;
                errMsg += "}";
            }
        } else {
            errMsg = curl_easy_strerror(res);
        }
    }
    curl_easy_cleanup(curl);
    return bValid ? "OK" : errMsg;
          }


void DrawTextCentered(const char *text)
{
    ImGui::Separator();
    ImGui::SetCursorPosX((ImGui::GetWindowWidth() - ImGui::CalcTextSize(text).x) / 5.f);
    ImGui::Text(text);
    ImGui::Separator();
}
 
#define IM_CLAMP(V, MN, MX)     ((V) < (MN) ? (MN) : (V) > (MX) ? (MX) : (V))
namespace Settings
{
    static int Tab = 1;
}

	EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);

    EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
        eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
        eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
        if (glWidth <= 0 || glHeight <= 0)
            return orig_eglSwapBuffers(dpy, surface);

        if (!g_App)
            return orig_eglSwapBuffers(dpy, surface);

        screenWidth = ANativeWindow_getWidth(g_App->window);
        screenHeight = ANativeWindow_getHeight(g_App->window);
        density = AConfiguration_getDensity(g_App->config);
            if (!initImGui) {
            InitTexture();
      ImGui::CreateContext();
  
                  ImGuiStyle& style = ImGui::GetStyle();
				 
			//ImportFonts();
		style.WindowRounding = 5.0f;
        style.FrameRounding = 9.0f;
		style.ChildRounding = 5.0f;
        style.ScrollbarRounding = 5.0f;
		style.ScrollbarSize = 13.0f;
		style.GrabMinSize = 9.0f;
		style.FrameBorderSize = 0.0f;
		style.WindowBorderSize = 0.0f;
		
		style.ItemSpacing = ImVec2(6,4);
		style.ItemInnerSpacing = ImVec2(12,3);
        style.WindowTitleAlign = ImVec2(0.5, 0.5);
		style.ButtonTextAlign = ImVec2(0.5,0.5);
	//	style.WindowSize = ImVec2(300,180);
        style.FramePadding = ImVec2(4,3);
		style.WindowPadding = ImVec2(10,10);//12 12 for center
            style.Colors[ImGuiCol_Text]                  = ImColor(255, 255, 255,255);
        style.Colors[ImGuiCol_TextDisabled]          = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        style.Colors[ImGuiCol_WindowBg]              = ImColor(24, 24, 24,255);
        style.Colors[ImGuiCol_ChildBg]               = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_PopupBg]               = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_Border]                = ImColor(255, 87, 34,255);   //ImVec4(0.518f, 0.557f, 0.592f, 1.00f);
        style.Colors[ImGuiCol_BorderShadow]          = ImColor(255, 87, 34,255);;

        style.Colors[ImGuiCol_FrameBg]               = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_FrameBgActive]         = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_FrameBgHovered]        = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_TitleBg]               = ImColor(24, 24, 24,255);
        style.Colors[ImGuiCol_TitleBgActive]         = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_TitleBgCollapsed]      = ImColor(0, 0, 0,110);
		
        style.Colors[ImGuiCol_MenuBarBg]             = ImColor(24, 24, 24,255);
        style.Colors[ImGuiCol_ScrollbarBg]           = ImColor(24, 24, 24,255);
        style.Colors[ImGuiCol_ScrollbarGrab]         = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_ScrollbarGrabHovered]  = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_ScrollbarGrabActive]   = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_CheckMark]             = ImColor(255, 87, 34,255);
        style.Colors[ImGuiCol_SliderGrab]            = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_SliderGrabActive]      = ImColor(32, 32, 32,255);

        style.Colors[ImGuiCol_Separator]             = ImVec4(0.00f, 0.89f, 1.00f, 0.00f);
        style.Colors[ImGuiCol_SeparatorActive]       = ImVec4(0.00f, 0.89f, 1.00f, 0.00f);
        style.Colors[ImGuiCol_SeparatorHovered]      = ImVec4(0.00f, 0.89f, 1.00f, 0.00f);

        style.Colors[ImGuiCol_Button]                = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_ButtonActive]          = ImColor(255, 87, 34,255);
        style.Colors[ImGuiCol_ButtonHovered]         = ImColor(255, 87, 34,255);

        style.Colors[ImGuiCol_Header]                = ImColor(32, 32, 32,255);
        style.Colors[ImGuiCol_HeaderActive]          = ImColor(255, 87, 34,255);
        style.Colors[ImGuiCol_HeaderHovered]         = ImColor(255, 87, 34,255);

        style.Colors[ImGuiCol_ResizeGrip]            = ImVec4(1.00f, 1.00f, 1.00f, 0.85f);
        style.Colors[ImGuiCol_ResizeGripHovered]     = ImVec4(1.00f, 1.00f, 1.00f, 0.60f);
        style.Colors[ImGuiCol_ResizeGripActive]      = ImVec4(1.00f, 1.00f, 1.00f, 0.90f);
        style.Colors[ImGuiCol_PlotLines]             = ImColor(255, 87, 34,255);
        style.Colors[ImGuiCol_PlotLinesHovered]      = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram]         = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogramHovered]  = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg]        = ImVec4(0.00f, 0.00f, 1.00f, 0.35f);

                      style.ScaleAllSizes(std::max(2.5f, density / 200.0f));
					   style.ScrollbarSize /= 1;
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");

                    ImGuiIO &io = ImGui::GetIO();

            io.ConfigWindowsMoveFromTitleBarOnly = true;
            io.IniFilename = NULL;

            static const ImWchar icons_ranges[] = { 0xf000, 0xf3ff, 0 };
            ImFontConfig icons_config;

            ImFontConfig CustomFont;
            CustomFont.FontDataOwnedByAtlas = false;

            icons_config.MergeMode = true;
            icons_config.PixelSnapH = true;
            icons_config.OversampleH = 2.5;
            icons_config.OversampleV = 2.5;
  Ayanfont = io.Fonts->AddFontFromMemoryTTF((void *)Ayanfont_data, Ayanfont_size, 30.0f, NULL, io.Fonts->GetGlyphRangesDefault());     
       io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(Custom), sizeof(Custom), 26.f, &CustomFont);
       io.Fonts->AddFontFromMemoryCompressedTTF(font_awesome_data, font_awesome_size, 30.0f, &icons_config, icons_ranges);
      NHKModFont = io.Fonts->AddFontFromMemoryTTF(const_cast<std::uint8_t*>(PROGGYCLEAN_), sizeof(PROGGYCLEAN_), 22.0f);

            ImFontConfig cfg;
            cfg.SizePixels = ((float) density / 60.0f);
            io.Fonts->AddFontDefault(&cfg);

            memset(&Config, 0, sizeof(sConfig));
//

// ===============================ESPCOLOR ================================== // 

        Config.ColorsESP.Line = CREATE_COLOR(0, 0, 139, 255);
        Config.ColorsESP.Box = CREATE_COLOR(0, 0, 139, 255);
        Config.ColorsESP.Name = CREATE_COLOR(255, 0, 0, 255);
        Config.ColorsESP.Vehicle = CREATE_COLOR(255, 0, 0, 255);
	    Config.ColorsESP.Skeletonbot = CREATE_COLOR(255, 255, 255, 255);
        Config.ColorsESP.BotNv = CREATE_COLOR(255, 255, 0, 255);
           Config.ColorsESP.BotNn = CREATE_COLOR(255, 0, 0, 255);
           Config.ColorsESP.Skeletonnon = CREATE_COLOR(255, 0, 0, 255);
           Config.ColorsESP.PotNv = CREATE_COLOR(0, 255, 0, 255);
           Config.ColorsESP.PotNn = CREATE_COLOR(255, 0, 0, 255);
		   Config.ColorsESP.nonbot = CREATE_COLOR(150, 150, 150, 255);
           Config.ColorsESP.SkeletonVisible = CREATE_COLOR(0, 255, 0, 255);
           Config.ColorsESP.Skeleton = CREATE_COLOR(255, 0, 0, 255);
		   Config.AimBot.Recc = 1.074f;
           initImGui = true;
        }

        ImGuiIO &io = ImGui::GetIO();
 
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
    ImGui::NewFrame();
DrawESP(ImGui::GetBackgroundDrawList());

		static bool anticrack = true; 	
			
	// ==========    @𝗖𝗵𝗼𝘂𝗱𝗵𝗮𝗿𝘆𝗥𝗕𝗚    ========================== //

ImGui::SetNextWindowSize(ImVec2((float) glWidth * 0.40f, (float) glHeight * 0.90f), ImGuiCond_Once);

            //NameMod
		
               if (ImGui::Begin(OBFUSCATE(" AYAN CHEATS 3.6 | ARM-32 BIT " ), 0, ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoResize )) {
          static bool isLogin = false;
	 
//	 if (ImGui::Begin(MOD_NAME.c_str()), 0, ImGuiWindowFlags_NoBringToFrontOnFocus ) {
   //    static bool isLogin = false;

            static std::string err;
            if (!isLogin) {
            
            SuperText("CHECKING KEY");
            ImGui::PushItemWidth(-1);
            static char s[64];
            ImGui::InputText("##key", s, sizeof s);
            ImGui::PopItemWidth();

            if (ImGui::Button(" Paste Key ", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                auto key = getClipboardText();
                strncpy(s, key.c_str(), sizeof s);
            }

            static std::string err;
            if (ImGui::Button(" Login ", ImVec2(ImGui::GetContentRegionAvailWidth(), 0))) {
                err = Login(s);
                if (err == "OK") {
                    isLogin = bValid && g_Auth == g_Token;
                }
            }

            if (!err.empty() && err != "OK") {
                ImGui::Text("Error: %s", err.c_str());
                
                
            }


            } else{

                {

					static int tab = 1;
					
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| 𝐌𝐚𝐝𝐞𝐁𝐲𝐃𝐞𝐦𝐨𝐧 |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\\
         
	//ImGui::SameLine();		
				//ImGui::RadioButton("ICELAND BYPASS", &island);
             //   draw->AddImageRounded(Logo.textureId, ImVec2(pos.x + 40, pos.y + 500), ImVec2(pos.x + 140, pos.y + 600), ImVec2(0,0), ImVec2(1,1), ImColor(1.0f,1.0f,1.0f), 100.0f, ImDrawFlags_RoundCornersAll);                                
                 ImGui::Image((ImTextureID)Logo.textureId, ImVec2(100 , 100));
                       
				//	Config.Bypass=true;
				ImGui::Columns(2);
            ImGui::SetColumnOffset(1, 145);
					
					{
					
                    

					
						
				

                if (ImGui::Button("ESP", ImVec2(100, 100)))
                            tab = 1;

                        
                      
                     /*   if (ImGui::Button("ITEM", ImVec2(100, 100)))
                            tab = 2; */

                        
                        
                       /*  if (ImGui::Button("BT", ImVec2(100, 100)))
                            tab = 3;  */

                      
							
                         if (ImGui::Button( "AIM", ImVec2(100, 100)))
                            tab = 4;

                        	
                        if (ImGui::Button( "SDK", ImVec2(100, 100)))
                            tab = 5;
                        
                            
							
							
                        
					//@DEADSPIOP
						}
						
						
						ImGui::NextColumn();
						
							
                        if (tab == 1) {
							

        
				ImGui::TableNextColumn();  
                ImGui::Checkbox("Line", &Config.PlayerESP.Line);
				ImGui::TableNextColumn();  
				ImGui::Checkbox("Skeleton", &Config.PlayerESP.Skeleton);
				ImGui::TableNextColumn();
				ImGui::Checkbox("Health", &Config.PlayerESP.Health);
				ImGui::TableNextColumn();  
				ImGui::Checkbox("Name", &Config.PlayerESP.Name);
				ImGui::TableNextColumn();
				ImGui::Checkbox("Distance", &Config.PlayerESP.Distance);
				ImGui::TableNextColumn();  
				ImGui::Checkbox("TeamID", &Config.PlayerESP.TeamID);
	             ImGui::TableNextColumn();     
				ImGui::Checkbox("Vehicle", &Config.PlayerESP.Vehicle);
				ImGui::TableNextColumn();
				ImGui::Checkbox("LootBox", &Config.PlayerESP.LootBox);
				ImGui::TableNextColumn();
				ImGui::Checkbox("Granade", &Config.PlayerESP.Grenade);
                        }
					
                      /*  if (tab == 2) {
					
ImGui::Spacing();    
ImGui::Text("ESP Loot Item");
                            ImGui::Spacing();

                            for (auto &i : items_data) {
                                if (ImGui::TreeNode(i["Category"].get<std::string>().c_str())) {
                                    ImGui::Spacing();
                                    for (auto &item : i["Items"]) {
                                        ImGui::Checkbox(item["itemName"].get<std::string>().c_str(),
                                                        (bool *) &Items[item["itemId"].get<int>()]);
                                       
                                    }

                                    ImGui::TreePop();
                                   
                                   
                                }
                            }

                        } */
                       if (tab == 3) {

SuperText("COMING SOON");
              ImGui::Text("DEVELOPER:- @AYAN_CHEATS ");


                        }
                  //@DEADSPIOP
             
                        if (tab == 4) {
                          
                          
                         ImGui::Text("AIMBOT ");      
			ImGui::Separator();
                ImGui::Text("Aimbot Menu ");
				ImGui::Separator();
				ImGui::Checkbox("Enable Aimbot", &Config.AimBot.Enable);
				ImGui::SliderFloat("   ", &FOVSizea, 0.0f, 220.0f, "%.3f Size", 0);
			//	ImGui::SliderFloat("Aim Smoothness", &AimSmooth, 3.7f, 10.0f,"%.1f" );
			    Config.AimBot.RecoilComparison = true;
				Config.AimBot.Recc = 1.3f;
             Config.AimBot.Meter = 200;
			//    AimSmooth, 2.3f,
			    ImGui::TableNextColumn();  
				ImGui::Checkbox("Ignore Knocked", &Config.AimBot.IgnoreKnocked); 
				ImGui::SameLine();
				ImGui::Checkbox("Ignore Bot", &Config.AimBot.IgnoreBot);
				ImGui::SameLine();
				ImGui::Checkbox("VisCheck", &Config.AimBot.VisCheck);
				ImGui::TableNextColumn();
				static const char *triggers[] = {"None", "Shooting", "Scoping", "Both (Shooting & Scoping)", "Any (Shooting / Scoping"};
                ImGui::Combo("##Trigger", (int *) &Config.AimBot.Trigger, triggers, 5, -1);
				ImGui::TableNextColumn();
				static const char *targets[] = {"Body"," Head"};
                ImGui::Combo("##Target", (int *) &Config.AimBot.Target, targets, 2, -1);
				ImGui::TableNextColumn();
                        
                          }
             
             

                   

						
							
                        if (tab == 5) {
			
	SuperText("COMING SOON");
              ImGui::Text("DEVELOPER:- @AYAN_CHEATS ");

                     }				
                }
            }
        }
        
	
	 

    ImGui::End();
    ImGui::Render();
    
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        return orig_eglSwapBuffers(dpy, surface);
    }



     
	

#define SLEEP_TIME 1000LL / 60LL

    [[noreturn]] void *maps_thread(void *) {
        while (true) {
					
        auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
	  
        if (FASTPERA) {
  if (g_LocalPlayer->ParachuteState == static_cast<EParachuteState>(1) || g_LocalPlayer->ParachuteState == static_cast<EParachuteState>(2)) // 1 = jump from plane 2 = after parachute  0 = ground
  {
  GetWorld()->PersistentLevel->WorldSettings->MinUndilatedFrameTime = 0.100f;
  }else{
  GetWorld()->PersistentLevel->WorldSettings->MinUndilatedFrameTime = 0.00050000002f;  
  }
  }
		
	
            std::vector<sRegion> tmp;
            char line[512];
            FILE *f = fopen("/proc/self/maps", "r");
            if (f) {
                while (fgets(line, sizeof line, f)) {
                    uintptr_t start, end;
                    char tmpProt[16];
                    if (sscanf(line, "%" PRIXPTR "-%" PRIXPTR " %16s %*s %*s %*s %*s", &start, &end, tmpProt) > 0) {
                        if (tmpProt[0] != 'r') {
                            tmp.push_back({start, end});
                        }
                    }
                }
                fclose(f);
            }
            trapRegions = tmp;
        
            auto td = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() - t1;
            std::this_thread::sleep_for(std::chrono::milliseconds(std::max(std::min(0LL, SLEEP_TIME - td), SLEEP_TIME)));
        }
    }
 
void FixGameCrash()
{
    system("rm -rf /data/data/com.pubg.imobile/files");
    system("rm -rf /data/data/com.pubg.imobile/files/ano_tmp");
    system("touch /data/data/com.pubg.imobile/files/ano_tmp");
    system("chmod 000 /data/data/com.pubg.imobile/files/ano_tmp");
    system("rm -rf /data/data/com.pubg.imobile/files/obblib");
    system("touch /data/data/com.pubg.imobile/files/obblib");
    system("chmod 000 /data/data/com.pubg.imobile/files/obblib");
    system("rm -rf /data/data/com.pubg.imobile/files/xlog");
    system("touch /data/data/com.pubg.imobile/files/xlog");
    system("chmod 000 /data/data/com.pubg.imobile/files/xlog");
    system("rm -rf /data/data/com.pubg.imobile/app_bugly");
    system("touch /data/data/com.pubg.imobile/app_bugly");
    system("chmod 000 /data/data/com.pubg.imobile/app_bugly");
    system("rm -rf /data/data/com.pubg.imobile/app_crashrecord");
    system("touch /data/data/com.pubg.imobile/app_crashrecord");
    system("chmod 000 /data/data/com.pubg.imobile/app_crashrecord");
    system("rm -rf /data/data/com.pubg.imobile/app_crashSight");
    system("touch /data/data/com.pubg.imobile/app_crashSight");
    system("chmod 000 /data/data/com.pubg.imobile/app_crashSight");
}

void *main_thread(void *) {  
FixGameCrash();
       UE4 = Tools::GetBaseAddress("libUE4.so");
        while (!UE4) {
            UE4 = Tools::GetBaseAddress("libUE4.so");
            sleep(1);
        }
         
        while (!g_App) {
            g_App = *(android_app **) (UE4 + GNativeAndroidApp_Offset);
            sleep(1);
        }            
        

        FName::GNames = GetGNames();
        while (!FName::GNames) {
            FName::GNames = GetGNames();
            sleep(1);
        }
        UObject::GUObjectArray = (FUObjectArray *) (UE4 + GUObject_Offset);
        DobbyHook((void *)DobbySymbolResolver("/system/lib/libandroid.so", "ANativeWindow_getWidth"), (void *)_ANativeWindow_getWidth, (void **)&orig_ANativeWindow_getWidth);
    DobbyHook((void *)DobbySymbolResolver("/system/lib/libandroid.so", "ANativeWindow_getHeight"), (void *)_ANativeWindow_getHeight, (void **)&orig_ANativeWindow_getHeight);
    DobbyHook((void *)DobbySymbolResolver("/system/lib/libinput.so", "_ZN7android13InputConsumer21initializeMotionEventEPNS_11MotionEventEPKNS_12InputMessageE"), (void *)onInputEvent, (void **)&orig_onInputEvent);
    DobbyHook((void *)DobbySymbolResolver("/system/lib/libEGL.so", "eglSwapBuffers"), (void *)_eglSwapBuffers, (void **)&orig_eglSwapBuffers);
	

        pthread_t t;
        pthread_create(&t, 0, maps_thread, 0);
        items_data = json::parse(JSON_ITEMS);
        return 0;
    }
    __attribute__((constructor)) void _init() {
        pthread_t t;
        pthread_create(&t, 0, main_thread, 0);
        
    }
    
