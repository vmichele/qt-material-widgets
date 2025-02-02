#include "mainwindow.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QListWidget>
#include "avatarsettingseditor.h"
#include "badgesettingseditor.h"
#include "checkboxsettingseditor.h"
#include "fabsettingseditor.h"
#include "containedbuttonsettingseditor.h"
#include "textbuttonsettingseditor.h"
#include "iconbuttonsettingseditor.h"
#include "progresssettingseditor.h"
#include "circularprogresssettingseditor.h"
#include "slidersettingseditor.h"
#include "radiobuttonsettingseditor.h"
#include "togglesettingseditor.h"
#include "textfieldsettingseditor.h"
#include "tabssettingseditor.h"
#include "snackbarsettingseditor.h"
#include "dialogsettingseditor.h"
#include "drawersettingseditor.h"
#include "scrollbarsettingseditor.h"
#include "appbarsettingseditor.h"
#include "autocompletesettingseditor.h"
#include "menusettingseditor.h"
#include "outilinedbuttonsettingseditor.h"



///TBR
#include "qtmaterialtextbutton.h"
#include "qtmaterialoutlinedbutton.h"
#include "qtmaterialcontainedbutton.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *widget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    widget->setLayout(layout);

    QStackedLayout *stack = new QStackedLayout;
    QListWidget *list = new QListWidget;

    layout->addWidget(list);
    layout->addLayout(stack);

    layout->setStretch(1, 2);

    setCentralWidget(widget);

    AvatarSettingsEditor *avatar = new AvatarSettingsEditor;
    BadgeSettingsEditor *badge = new BadgeSettingsEditor;
    CheckBoxSettingsEditor *checkbox = new CheckBoxSettingsEditor;
    FloatingActionButtonSettingsEditor *fab = new FloatingActionButtonSettingsEditor;
    ContainedButtonSettingsEditor *containedButton = new ContainedButtonSettingsEditor;
    TextButtonSettingsEditor *textButton = new TextButtonSettingsEditor;
    IconButtonSettingsEditor *iconButton = new IconButtonSettingsEditor;
    ProgressSettingsEditor *progress = new ProgressSettingsEditor;
    CircularProgressSettingsEditor *circularProgress = new CircularProgressSettingsEditor;
    SliderSettingsEditor *slider = new SliderSettingsEditor;
    RadioButtonSettingsEditor *radioButton = new RadioButtonSettingsEditor;
    ToggleSettingsEditor *toggle = new ToggleSettingsEditor;
    TextFieldSettingsEditor *textField = new TextFieldSettingsEditor;
    TabsSettingsEditor *tabs = new TabsSettingsEditor;
    SnackbarSettingsEditor *snackbar = new SnackbarSettingsEditor;
    DialogSettingsEditor *dialog = new DialogSettingsEditor;
    DrawerSettingsEditor *drawer = new DrawerSettingsEditor;
    ScrollBarSettingsEditor *scrollBar = new ScrollBarSettingsEditor;
    AppBarSettingsEditor *appBar = new AppBarSettingsEditor;
    AutoCompleteSettingsEditor *autocomplete = new AutoCompleteSettingsEditor;
    MenuSettingsEditor *menu = new MenuSettingsEditor;
    OutilinedButtonSettingsEditor *outlinedButton = new OutilinedButtonSettingsEditor;

    ///TBR
    auto w = new QWidget;
    w->setStyleSheet("QWidget { background: white; }");
    auto l = new QVBoxLayout;
    auto tb = new QtMaterialTextButton("text button");
    tb->setFixedWidth(300);
    l->addWidget(tb);
    auto ob = new QtMaterialOutlinedButton("outlined button");
    ob->setFixedWidth(300);
    l->addWidget(ob);
    auto cb = new QtMaterialContainedButton("contained button");
    cb->setFixedWidth(300);
    l->addWidget(cb);
    layout->setAlignment(tb, Qt::AlignCenter);
    layout->setAlignment(ob, Qt::AlignCenter);
    layout->setAlignment(cb, Qt::AlignCenter);
    w->setLayout(l);
    stack->addWidget(w);
    list->addItem("Buttons");
    ///TBR

    stack->addWidget(appBar);
    stack->addWidget(autocomplete);
    stack->addWidget(avatar);
    stack->addWidget(badge);
    stack->addWidget(checkbox);
    stack->addWidget(circularProgress);
    stack->addWidget(containedButton);
    stack->addWidget(dialog);
    stack->addWidget(drawer);
    stack->addWidget(fab);
    stack->addWidget(iconButton);
    stack->addWidget(menu);
    stack->addWidget(outlinedButton);
    stack->addWidget(progress);
    stack->addWidget(radioButton);
    stack->addWidget(scrollBar);
    stack->addWidget(slider);
    stack->addWidget(snackbar);
    stack->addWidget(tabs);
    stack->addWidget(textButton);
    stack->addWidget(textField);
    stack->addWidget(toggle);

    list->addItem("App Bar");
    list->addItem("Auto Complete");
    list->addItem("Avatar");
    list->addItem("Badge");
    list->addItem("Checkbox");
    list->addItem("Circular Progress");
    list->addItem("Contained Button");
    list->addItem("Dialog");
    list->addItem("Drawer");
    list->addItem("Floating Action Button");
    list->addItem("Icon Button");
    list->addItem("Menu");
    list->addItem("Outlined Button");
    list->addItem("Progress");
    list->addItem("Radio Button");
    list->addItem("ScrollBar");
    list->addItem("Slider");
    list->addItem("Snackbar");
    list->addItem("Tabs");
    list->addItem("Text Button");
    list->addItem("Text Field");
    list->addItem("Toggle");

    list->setCurrentRow(0);

    QObject::connect(list,  &QListWidget::currentItemChanged,
        [=](QListWidgetItem *current, QListWidgetItem *previous)
    {
        Q_UNUSED(current)
        Q_UNUSED(previous)
        stack->setCurrentIndex(list->currentRow());
    });
}

MainWindow::~MainWindow()
{
}
