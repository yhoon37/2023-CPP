#ifndef UNTITLED_NOTIFICATION_H
#define UNTITLED_NOTIFICATION_H
#include <iostream>
#include <ctime>

class NotificationBuilder;

class Notification {
public:
    static NotificationBuilder create();
    friend class NotificationBuilder;
    friend std::ostream& operator << (std::ostream &os, const Notification& n);

private:
    Notification() = default;
    int icon;
    std::string appName = "PNU";
    std::time_t timestamp = std::time(nullptr);
    std::string title;
    std::string text;
    int priority;
};

class NotificationBuilder {
public:
    //user-defined conversion function
    operator Notification() const { return std::move(notification); }
    NotificationBuilder& setSmallIcon(int icon);
    NotificationBuilder& setContentTitle(std::string title);
    NotificationBuilder& setContentText(std::string text);
    NotificationBuilder& setPriority(int priority);
private:
    Notification notification;
};


#endif //UNTITLED_NOTIFICATION_H
