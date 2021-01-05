#ifndef SONG_H
#define SONG_H
#include <QString>

class Song
{
public:
    Song(QString id,
        QString name,
        QString artist,
        QString name_artist,
        QString songdir,
        QString imagedir,
        QString lyricdir,
        QString albumdir)
    {
        this->id=id;
        this->name=name;
        this->artist=artist;
        this->name_artist=name_artist;
        this->songdir=songdir;
        this->imagedir=imagedir;
        this->lyricdir=lyricdir;
        this->albumdir=albumdir;
    }
    Song(){}
    QString getName(){return name;}
    QString getId(){return id;}
    QString getArtist(){return artist;}
    QString getNameArtist(){return name_artist;}
    QString getSongUrl(){return songdir;}
    QString getImageUrl(){return imagedir;}
    QString getLyricUrl(){return lyricdir;}
    QString getAlbumUrl(){return albumdir;}
private:
    QString name;
    QString artist;
    QString id;
    QString name_artist;
    QString songdir;
    QString albumdir;
    QString imagedir;
    QString lyricdir;
};

#endif // SONG_H
