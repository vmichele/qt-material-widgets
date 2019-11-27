#ifndef QTMATERIALICONBUTTON_P_H
#define QTMATERIALICONBUTTON_P_H

#include <QtGlobal>

class QtMaterialIconButton;
class QtMaterialRippleOverlay;
class QColor;

#include <QtWidgets/QMenu>
#include <QPointer>

class QtMaterialIconButtonPrivate
{
    Q_DISABLE_COPY(QtMaterialIconButtonPrivate)
    Q_DECLARE_PUBLIC(QtMaterialIconButton)

public:
    QtMaterialIconButtonPrivate(QtMaterialIconButton *q);
    virtual ~QtMaterialIconButtonPrivate();

    void init();
    void resetLayoutItemMargins();
    void updateRipple();

    QtMaterialIconButton    *const q_ptr;
    QtMaterialRippleOverlay *rippleOverlay;
    QColor                   color;
    QColor                   disabledColor;
    bool                     useThemeColors;

    QPointer<QMenu> menu;
};

#endif // QTMATERIALICONBUTTON_P_H
