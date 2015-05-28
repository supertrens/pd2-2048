#include "myclass.h"



GAMEPLAY::GAMEPLAY(QObject *parent)
    : QObject(parent)
{
    bestScoreVar = 0;
    scoreVar = 0;
    connect(this, SIGNAL(backed()), this, SLOT(undo()));
    srand(time(0));
}

GAMEPLAY::~GAMEPLAY()
{
}

void GAMEPLAY::startUpFunction()
{
    initBoard();
}

void GAMEPLAY::moveDir(Move_Direction direction)
{
    addNumber(direction);
    moveNumber(direction);
    refreshBoard (addPoint || movePoint );

    // Condition to see if there is a new Best Score
    bestScoreVar = (bestScoreVar < scoreVar)? scoreVar : bestScoreVar;


}

QColor GAMEPLAY::color(const int &index)
{

    int number = m_number[index];
    QColor color;
    switch(number) {
    case 0: color =    QColor ("#EEE4DA")   ; break;
    case 2: color =    QColor ("#EDE0C8")   ; break;
    case 4: color =    QColor("#F2B179")    ; break;
    case 8: color =    QColor("#F59563")    ; break;
    case 16: color =   QColor("#F67C5F")    ; break;
    case 32: color =   QColor("#F65E3B")    ; break;
    case 64: color =   QColor("#EDCF72")    ; break;
    case 128: color =  QColor("#EDCC61")    ; break;
    case 256: color =  QColor("#EDC850")    ; break;
    case 512: color =  QColor("#EDC53F")    ; break;
    case 1024: color = QColor("#EDC22E")    ; break;
    case 2048: color = QColor("#3C3A32")    ; break;
    case 4096: color = QColor("#776E62")    ; break;
    case 8192: color = QColor("#F9F6F2")    ; break;
    default: color = QColor(0, 0, 0); break;
    }
    return color;
}

QColor GAMEPLAY::numColor(const int &index)
{

    return ( m_number[index] < 8192 )? QColor(0, 0, 0) : QColor(255, 255, 255);

}

int GAMEPLAY::getScore() const
{
    return scoreVar;
}

int GAMEPLAY::getBestScore() const
{
    return bestScoreVar ;
}

int GAMEPLAY::getStep() const
{
    return stepVar;
}

int GAMEPLAY::getTotalStep() const
{
    return totalStepVar;
}


int GAMEPLAY::showBoard(const int &index)
{
    return m_number[index];
}

void GAMEPLAY::undo()
{
    if(stepVar > 0) {
        m_number = m_state[stepVar - 1];
        m_state.pop_back();
         stepVar -= 1;
    }
}

void GAMEPLAY::initBoard()
{
    m_number.clear();
    m_number = nouPanel(16, 0);
    int firstNum = rand() % 16;
    int secondNum = rand() % 16;
    while(firstNum == secondNum) {
        secondNum = rand() % 16;
    }
    m_number[firstNum] = 2;
    m_number[secondNum] = 2;
    scoreVar = 0;
    stepVar = 0;
    totalStepVar = 0;
    m_state.clear();
    m_state.push_back(m_number);
}

void GAMEPLAY::addNumber(Move_Direction direction)
{
    if(Move_Down == direction)
    {
        addPoint = false;
        for(int c = 0; c < COLUMNS; c++)
        {
            prevIndex = c;
            nextIndex = prevIndex + 4;
            while(nextIndex <= c + 12)
            {
                if(m_number[prevIndex] == 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 4;
                    continue;
                }
                if( m_number [nextIndex] == 0 ) {
                    nextIndex += 4;
                    continue;
                }
                if(m_number[prevIndex] != m_number[nextIndex] )
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 4;
                }
                else
                {
                    m_number[prevIndex] = 0;
                    m_number[nextIndex] += m_number[nextIndex];
                    scoreVar += m_number[nextIndex];
                    prevIndex = nextIndex + 4;
                    nextIndex = prevIndex + 4;
                    addPoint = true;
                }
            }
        }
    }

    if(Move_Up == direction)
    {
        addPoint = false;
         for(int c = 0; c < COLUMNS; c++)
          {
             prevIndex = c + 12;
             nextIndex = prevIndex - 4;

             while(nextIndex >= c)
             {
                if( m_number[prevIndex] == 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 4;
                    continue;
                }
                if( m_number[nextIndex] == 0)
                {
                    nextIndex -= 4;
                    continue;
                }
                if(m_number[prevIndex] != m_number[nextIndex])
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 4;
                }
                else
                {
                    m_number[prevIndex] = 0;
                    m_number[nextIndex] += m_number[nextIndex];
                    scoreVar += m_number[nextIndex];
                    prevIndex = nextIndex - 4;
                    nextIndex = prevIndex - 4;
                    addPoint = true;
                }
            }
        }
    }

    // The Right Control

    if(Move_Right == direction)
    {
        addPoint = false;
        for(int r = 0; r < ROWS; r++)
        {
            prevIndex = r * 4;
            nextIndex = prevIndex + 1;
            while(nextIndex <= r * 4 + 3)
            {
                if( m_number[prevIndex] == 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 1;
                    continue;
                }
                if(m_number[nextIndex] == 0)
                {
                    nextIndex += 1;
                    continue;
                }
                if(m_number[prevIndex] != m_number[nextIndex])
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 1;
                }

                else

                {
                    m_number[prevIndex] = 0;
                    m_number[nextIndex] += m_number[nextIndex];
                    scoreVar += m_number[nextIndex];
                    prevIndex = nextIndex + 1;
                    nextIndex = prevIndex + 1;
                    addPoint = true;
                }
            }
        }
    }

    // The Left Key Control LogicFlow

    if(Move_Left == direction)
    {
        addPoint = false;
        for(int r = 0; r < ROWS; r++)
        {
            prevIndex = r * 4 + 3;
            nextIndex = prevIndex - 1;
            while(nextIndex >= r * 4)
            {
                if(0 == m_number[prevIndex])
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 1;
                    continue;
                }
                if(0 == m_number[nextIndex]) {
                    nextIndex -= 1;
                    continue;
                }
                if(m_number[prevIndex] != m_number[nextIndex]) {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 1;
                } else {
                    m_number[prevIndex] = 0;
                    m_number[nextIndex] += m_number[nextIndex];
                    scoreVar += m_number[nextIndex];
                    prevIndex = nextIndex - 1;
                    nextIndex = prevIndex - 1;
                    addPoint = true;
                }
            }
        }
    }
}

void GAMEPLAY::moveNumber(Move_Direction direction)
{
    if(Move_Down == direction)
    {
        movePoint = false;
        for(int c = 0; c < COLUMNS; c++)
        {
            prevIndex = c + 12;
            nextIndex = prevIndex - 4;
            while(nextIndex >= c)
            {
                if( m_number[prevIndex] != 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 4;
                    continue;
                }

                if( m_number[nextIndex] == 0)
                {
                    nextIndex -= 4;
                    continue;
                }

                else
                {
                    m_number[prevIndex] = m_number[nextIndex];
                    m_number[nextIndex] = 0;
                    prevIndex = prevIndex - 4;
                    nextIndex = nextIndex - 4;
                    movePoint = true;
                }
            }
        }
    }

    // remove flag from direction
    if(Move_Up == direction)
    {
        movePoint = false;
        for(int c = 0; c < COLUMNS; c++)
        {
            prevIndex = c;
            nextIndex = prevIndex + 4;
            while(nextIndex <= c + 12)
            {
                if( m_number[prevIndex] != 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 4;
                    continue;
                }

                if( m_number[nextIndex]  == 0)
                {
                    nextIndex += 4;
                    continue;
                }
                else
                {
                    m_number[prevIndex] = m_number[nextIndex];
                    m_number[nextIndex] = 0;
                    prevIndex = prevIndex + 4;
                    nextIndex = nextIndex + 4;
                    movePoint = true;
                }
            }
        }
    }

    // Move Right

    if(Move_Right == direction)
    {
        movePoint = false;
        for(int r = 0; r < ROWS; r++)
        {
            prevIndex = r * 4 + 3;
            nextIndex = prevIndex - 1;
            while(nextIndex >= r * 4)
            {
                if (m_number[prevIndex] != 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex - 1;
                    continue;
                }
                if( m_number[nextIndex] == 0)
                {
                    nextIndex -= 1;
                    continue;
                }

                else
                {
                    m_number[prevIndex] = m_number[nextIndex];
                    m_number[nextIndex] = 0;
                    prevIndex = prevIndex - 1;
                    nextIndex = nextIndex - 1;
                    movePoint = true;
                }
            }
        }
    }


    // If Move left

    if(Move_Left == direction)
    {
        movePoint = false;
        for(int r = 0; r < ROWS; r++)
        {
            prevIndex = r * 4;
            nextIndex = prevIndex + 1;
            while(nextIndex <= r * 4 + 3)
            {
                if( m_number[prevIndex] != 0)
                {
                    prevIndex = nextIndex;
                    nextIndex = prevIndex + 1;
                    continue;
                }
                if(m_number[nextIndex] == 0)
                {
                    nextIndex += 1;
                    continue;
                }

                else
                {
                    m_number[prevIndex] = m_number[nextIndex];
                    m_number[nextIndex] = 0;
                    prevIndex = prevIndex + 1;
                    nextIndex = nextIndex + 1;
                    movePoint = true;
                }
            }
        }
    }
}

void GAMEPLAY::refreshBoard(bool fresh)
{
    if(fresh) {
        stepVar += 1;
        totalStepVar = stepVar;
        m_index.clear();
        for(size_t s = 0; s < m_number.size(); s++) {
            if(!m_number[s]) {
                m_index.push_back(s);
            }
        }
        int randIndex = rand() % m_index.size();
        m_number[m_index[randIndex]] = 2;
        m_state.push_back(m_number);
    }
}

void GAMEPLAY::finishGame()

{
    QGuiApplication::quit();
}

void GAMEPLAY::restartGame()
{
    QProcess::startDetached(QGuiApplication::applicationFilePath());
    exit(12);
}
