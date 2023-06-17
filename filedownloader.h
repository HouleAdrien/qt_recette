//! Declaration de la classe filedownloader.
//!\file filedownloader.h
//!\author Qt
//!\details cette classe provient du wiki de Qt et permet de télécharger une image d'internet : https://wiki.qt.io/Download_Data_from_URL
#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QByteArray>
#include <QNetworkRequest>

#if QT_VERSION >= 0x050100 //on inclut toutes les classes de Qt
#include <QtWidgets> /* tous les widgets de Qt5 /
#else
#include <QtGui> / tous les widgets de Qt4 */
#endif

class FileDownloader : public QObject
{
 Q_OBJECT
 public:
    //!\brief Constructeur de l'instance qui permet de télécharger un média
       //!\param QUrl l'url du média à récupérer
       //!\param QObject objet parent de l'instance
  explicit FileDownloader(QUrl imageUrl, QObject *parent = 0);
    //!\brief Destructeur de l'instance qui permet de télécharger un média
  virtual ~FileDownloader();
    //!\brief Envoie l'image téléchargée
       //!\return Les données récupérées
  QByteArray downloadedData() const;

 signals:
 //!\brief signal qui permet de savoir quand le téléchargement du média est terminé
       //!\param QNetworkReply est une donnée qui permet de savoir si le média existe
  void downloaded();

 private slots:
  //!\brief Permet de stocker le média téléchargé
      //!\param QNetworkReply est une donnée qui permet de savoir si le média existe
  void fileDownloaded(QNetworkReply* pReply);

 private:
//!\brief utiliser dans le mainwindow.cpp afin de charger une image avec la fonction loadimage et aussi la fonction afficher
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
};

#endif // FILEDOWNLOADER_H
