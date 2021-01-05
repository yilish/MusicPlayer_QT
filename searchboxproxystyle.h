#ifndef SEARCHBOXPROXYSTYLE_H
#define SEARCHBOXPROXYSTYLE_H
#include <QProxyStyle>

class SearchBoxProxyStyle: public QProxyStyle
{
public:
    SearchBoxProxyStyle();
protected:
    virtual void drawPrimitive(PrimitiveElement element, const QStyleOption * option,
                                   QPainter * painter, const QWidget * widget = 0) const;
};

#endif // SEARCHBOXPROXYSTYLE_H
