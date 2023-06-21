#ifndef INTERACTIVE_CANVAS_H
#define INTERACTIVE_CANVAS_H

#endif // INTERACTIVE_CANVAS_H

#include <QWidget>
#include <QImage>
#include <QList>
#include <QMouseEvent>

class Canvas : public QWidget {
    Q_OBJECT

public:
    explicit Canvas(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

private:
    QImage canvasImage;
    QList<QImage> stackImages;
    int currentImageIndex;
    QRect currentRect;
    QPoint startPoint;
    QPoint endPoint;
};

