//compile using  g++ Adapter.cpp -Wc++11-extensions -std=c++11

#include <string>
#include <iostream>
#include <memory>

enum AudioType  {
    MP3 =0,
    MP4 =1,
    VLC = 2
};

std::string getAudioTypeName(AudioType type){
    switch (type)
    {
        case MP3:
        return "MP3";
        case MP4:
        return "MP4";
        case VLC:
        return "VLC";
        default:
            break;
    }

    return "UNKNOWN";
}

class MediaPlayer{
    public:
    virtual void play(AudioType type,const std::string &filename) = 0;
};

class AdvancedMediaPlayer{
    public:
    virtual void playVLC(const std::string fileName) = 0;
    virtual void playMP4(const std::string fileName) = 0;
};

class VLCPlayer :public AdvancedMediaPlayer{
    public:
    void playVLC(const std::string fileName) override{
        std::cout<<"Playing vlc file. Name: "<<fileName<<std::endl;
    }
    void playMP4(const std::string fileName) override{
        //do nothing
        //std::cout<<"Playing mp4 file. Name: "<<fileName<<std::endl;
    }
};

class MP4Player :public AdvancedMediaPlayer{
    public:
    void playVLC(const std::string fileName) override{
        //do nothing
        //std::cout<<"Playing vlc file. Name: "<<fileName<<std::endl;
    }
    void playMP4(const std::string fileName) override{
        std::cout<<"Playing mp4 file. Name: "<<fileName<<std::endl;
    }
};

class MediaAdapter:public MediaPlayer{
    public:
    MediaAdapter(AudioType type){
        if(type == VLC){
            advancedMusicPlayer = std::make_shared<VLCPlayer>();
        }else if(type == MP4){
            advancedMusicPlayer = std::make_shared<MP4Player>();
        }

    }
    void play(AudioType type,const std::string &filename) override{
        if(type == VLC){
            advancedMusicPlayer->playVLC(filename);
        }else if(type == MP4){
            advancedMusicPlayer->playMP4(filename);
        }
    }
    private:
    std::shared_ptr<AdvancedMediaPlayer> advancedMusicPlayer;
};

class AudioPlayer : public MediaPlayer{
    private:
    std::shared_ptr<MediaAdapter> mediaAdapter;
    public:

    void play(AudioType type,const std::string &fileName) override{
        if(type == MP3){
            std::cout<<"player mp3 file. Name: "<<fileName<<std::endl;
        }else if(type == VLC || type == MP4){
            mediaAdapter = std::make_shared<MediaAdapter>(type);
            mediaAdapter->play(type,fileName);
        }else{
            std::cout<<"Invalid media. "<<getAudioTypeName(type);
            std::cout<<" format not supported."<<std::endl;
        }
    }
};

int main(){
    std::shared_ptr<AudioPlayer> player = std::make_shared<AudioPlayer>();
    player->play(MP3,"test1.mp3");
    player->play(MP4,"test2.mp4");
    player->play(VLC,"test3.vlc");
    return 0;
}