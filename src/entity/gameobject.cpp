#include "gameobject.h"

Effectiveness getEffectiveness(Element e1, Element e2)
{
    if( e1 == e2 ) return Effectiveness::Neutral;
    if( e1 == Element::Fire )
    {
        if( e2 == Element::Water )
        {
            return Effectiveness::Weak;
        }
        else
        {
            return Effectiveness::Strong;
        }
    }
    else if( e1 == Element::Water )
    {
        if( e2 == Element::Plant )
        {
            return Effectiveness::Weak;
        }
        else
        {
            return Effectiveness::Strong;
        }
    }
    else if( e1 == Element::Plant )
    {
        if( e2 == Element::Fire )
        {
            return Effectiveness::Weak;
        }
        else
        {
            return Effectiveness::Strong;
        }
    }
}
