#include <array>

#include <QLabel>
#include <QPixmap>
#include <QProgressBar>
#include <QSocketNotifier>
#include <QVariantAnimation>
#include <QWidget>

constexpr int spinner_fps = 30;
//constexpr QSize spinner_size = QSize(360, 360); 스피너 삭제 24/07/20
constexpr QSize spinner_BG_size = QSize(1920, 1080); // 스피너 배경이미지 추가 24/7/20

class TrackWidget : public QWidget  {
  Q_OBJECT
public:
  TrackWidget(QWidget *parent = nullptr);

private:
  void paintEvent(QPaintEvent *event) override;
  std::array<QPixmap, spinner_fps> track_imgs;
  QVariantAnimation m_anim;
};

class Spinner : public QWidget {
  Q_OBJECT

public:
  explicit Spinner(QWidget *parent = 0);

private:
  QLabel *text;
  QProgressBar *progress_bar;
  QSocketNotifier *notifier;

public slots:
  void update(int n);
};
