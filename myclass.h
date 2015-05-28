#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QObject>
#include <QColor>
#include <ctime>
#include <QGuiApplication>
#include <QProcess>
#include <QString>

#define ROWS 4
#define COLUMNS 4

class GAMEPLAY : public QObject
{
    Q_OBJECT
    Q_ENUMS(Move_Direction)
    Q_PROPERTY(int getScore READ getScore)
    Q_PROPERTY(int getBestScore READ getBestScore)
    Q_PROPERTY(int getStep READ getStep)
    Q_PROPERTY(int getTotalStep READ getTotalStep)

public:
    GAMEPLAY(QObject *parent = 0);
    ~GAMEPLAY();

    enum Move_Direction {
        Move_Up = 0,
        Move_Down,
        Move_Left,
        Move_Right,
        Move_Invalid
    };

    Q_INVOKABLE void startUpFunction();
    Q_INVOKABLE void moveDir(Move_Direction direction); //move
    Q_INVOKABLE QColor color(const int &index);
    Q_INVOKABLE QColor numColor(const int &index);

    int getScore() const;
    int getBestScore() const;
    int getStep() const;
    int getTotalStep() const;

signals:
    void backed(); //backed

public slots:
    int showBoard(const int &index); //show
    void undo(); //goback
    void finishGame(); // tO END THE GAME BY CTRL+Q
    void restartGame();

private:
    void initBoard(); //initNum
    void addNumber(Move_Direction direction);   //added
    void moveNumber(Move_Direction direction); //moved
    void refreshBoard(bool fresh);            //freshed


    //My  attributes
    typedef std::vector<int> nouPanel;
    typedef std::vector<nouPanel> nouState;

    int scoreVar;
    int bestScoreVar;
    int stepVar;
    int totalStepVar;


    nouPanel m_number;
    nouPanel m_index;
    nouState m_state;

    int prevIndex;
    int nextIndex;
    bool addPoint;
    bool movePoint; //movedFlag
};

#endif // GAMBEPLAY_H
