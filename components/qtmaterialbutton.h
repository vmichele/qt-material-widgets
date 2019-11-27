#ifndef QTMATERIALBUTTON_HXX
#define QTMATERIALBUTTON_HXX

#include <QtWidgets/QPushButton>
#include <QScopedPointer>

#include "lib/qtmaterialtheme.h"

class QtMaterialButtonPrivate;

class QtMaterialButton : public QPushButton
{
  Q_OBJECT

  Q_PROPERTY(QColor foregroundColor WRITE setForegroundColor READ foregroundColor)
  Q_PROPERTY(QColor backgroundColor WRITE setBackgroundColor READ backgroundColor)
  Q_PROPERTY(QColor overlayColor WRITE setOverlayColor READ overlayColor)
  Q_PROPERTY(QColor disabledForegroundColor WRITE setDisabledForegroundColor READ disabledForegroundColor)
  Q_PROPERTY(QColor disabledBackgroundColor WRITE setDisabledBackgroundColor READ disabledBackgroundColor)
  Q_PROPERTY(qreal fontSize WRITE setFontSize READ fontSize)

public:
  explicit QtMaterialButton(QWidget *parent = nullptr, Material::ButtonPreset preset = Material::NotCheckablePreset);
  explicit QtMaterialButton(const QString &text, QWidget *parent = nullptr, Material::ButtonPreset preset = Material::NotCheckablePreset);
  QtMaterialButton(const QString &text, Material::Role role, QWidget *parent = nullptr, Material::ButtonPreset preset = Material::NotCheckablePreset);
  ~QtMaterialButton() Q_DECL_OVERRIDE;

  void applyPreset(Material::ButtonPreset preset);

  void setUseThemeColors(bool value);
  bool useThemeColors() const;

  void setRole(Material::Role role);
  Material::Role role() const;

  void setForegroundColor(const QColor &color);
  QColor foregroundColor() const;

  void setBackgroundColor(const QColor &color);
  QColor backgroundColor() const;

  void setOverlayColor(const QColor &color);
  QColor overlayColor() const;

  void setDisabledForegroundColor(const QColor &color);
  QColor disabledForegroundColor() const;

  void setDisabledBackgroundColor(const QColor &color);
  QColor disabledBackgroundColor() const;

  void setFontSize(qreal size);
  qreal fontSize() const;

  void setHaloVisible(bool visible);
  bool isHaloVisible() const;

  void setOverlayStyle(Material::OverlayStyle style);
  Material::OverlayStyle overlayStyle() const;

  void setRippleStyle(Material::RippleStyle style);
  Material::RippleStyle rippleStyle() const;

  void setIconPlacement(Material::ButtonIconPlacement placement);
  Material::ButtonIconPlacement iconPlacement() const;

  void setCornerRadius(qreal radius);
  qreal cornerRadius() const;

  void setBackgroundMode(Qt::BGMode mode);
  Qt::BGMode backgroundMode() const;

  void setBaseOpacity(qreal opacity);
  qreal baseOpacity() const;

  void setCheckable(bool value);

  void setHasFixedRippleRadius(bool value);
  bool hasFixedRippleRadius() const;

  void setFixedRippleRadius(qreal radius);

  void setTextAlignment(Qt::Alignment alignment);
  Qt::Alignment textAlignment() const;

  QSize sizeHint() const Q_DECL_OVERRIDE;

protected:
  enum {
      IconPadding = 12
  };

  QtMaterialButton(QtMaterialButtonPrivate &d, QWidget *parent = nullptr, Material::ButtonPreset preset = Material::NotCheckablePreset);

  void checkStateSet() Q_DECL_OVERRIDE;
  void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
  void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
  void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

  virtual void paintBackground(QPainter *painter);
  virtual void paintHalo(QPainter *painter);
  virtual void paintForeground(QPainter *painter);

  virtual void updateClipPath();

  void enterEvent(QEvent* event) Q_DECL_OVERRIDE;
  void leaveEvent(QEvent* event) Q_DECL_OVERRIDE;

  const QScopedPointer<QtMaterialButtonPrivate> d_ptr;

private:
    Q_DISABLE_COPY(QtMaterialButton)
    Q_DECLARE_PRIVATE(QtMaterialButton)
};

#endif // QTMATERIALBUTTON_HXX
