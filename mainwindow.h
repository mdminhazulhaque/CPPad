#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "highlighter.h"

#include <QMainWindow>
#include <QTextEdit>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

public slots:
    void about();
    void newFile();
    void openFile(const QString &path = QString());
    void open();
    bool save();
    bool saveAs();
    void run();


private:
    void setupEditor();
    void setupFileMenu();
    void setupHelpMenu();
    void createActions();
    void createMenus();
    void createToolBars();
    void createStatusBar();
    void readSettings();
    void writeSettings();
    bool maybeSave();
    void loadFile(const QString &fileName);
    bool saveFile(const QString &fileName);
    void setCurrentFile(const QString &fileName);
    QString strippedName(const QString &fullFileName);


    QString curFile;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *saveAsAct;
    QAction *exitAct;

    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;

    QAction *runAct;

    QAction *aboutAct;
    QAction *aboutQtAct;

    QTextEdit *editor;
    Highlighter *highlighter;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
