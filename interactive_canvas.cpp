#include <QtWidgets>

class Canvas : public QWidget {
public:
    Canvas(QWidget *parent = nullptr) : QWidget(parent) {
        setMouseTracking(true);
        canvasImage = QImage(800, 600, QImage::Format_RGB32);
        canvasImage.fill(Qt::white);
        stackImages.append(QImage("T:/2022-06-03_application_photo.png"));  // Add your image paths here
        stackImages.append(QImage("T:/2022-06-03_application_photo.png"));
        currentImageIndex = 0;
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.drawImage(0, 0, stackImages[currentImageIndex]);
        painter.drawImage(0, 0, canvasImage);
        painter.setPen(QPen(Qt::blue, 2));
        painter.drawRect(currentRect);
    }

    void mousePressEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            startPoint = event->pos();
            currentRect = QRect(startPoint, startPoint);
        }
    }

    void mouseMoveEvent(QMouseEvent *event) override {
        if (event->buttons() & Qt::LeftButton) {
            currentRect.setBottomRight(event->pos());
            update();
        }
    }

    void mouseReleaseEvent(QMouseEvent *event) override {
        if (event->button() == Qt::LeftButton) {
            endPoint = event->pos();
            QRect selectedRect = QRect(startPoint, endPoint).normalized();
            // Do something with the selectedRect (e.g., store, process, etc.)
            qDebug() << "Selected Rectangle:" << selectedRect;
        }
    }

private:
    QImage canvasImage;
    QList<QImage> stackImages;
    int currentImageIndex;
    QRect currentRect;
    QPoint startPoint;
    QPoint endPoint;
};
