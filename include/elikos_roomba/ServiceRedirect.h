#ifndef SERVICE_REDIRECT_H
#define SERVICE_REDIRECT_H

#include "elikos_roomba/Robot.h"        // use topic names, service names, and other values

// names
static const std::string GROUNDROBOT_NAMESPACE_PREFIX = "groundrobot";      // ground robot namespace prefix (only missing robot id)
static const std::string OBSTACLEROBOT_NAMESPACE_PREFIX = "obstaclerobot";  // obstacle robot namespace prefix (only missing robot id)


class ServiceRedirect
{
    public:
        /*
         * Constructor
         * groundrobotQty: number of ground robots
         * obstaclerobotQty: number of obstacle robots
         */
        ServiceRedirect(ros::NodeHandle& n);
        ~ServiceRedirect();
    
    protected:
        ros::NodeHandle& n_;

        int groundrobotQty_;
        int obstaclerobotQty_;
    
    private:
        /*===========================
         * Services
         *===========================*/
        /* Global robot activation service  */
        ros::ServiceServer activate_srv_;
        /* Global robot deactivation service */
        ros::ServiceServer deactivate_srv_;
        /* Global robot toggle activate service */
        ros::ServiceServer toglActivate_srv_;
        /* Global robot reset service */
        ros::ServiceServer reset_srv_;

        /* Robot activation service clients */
        std::vector<ros::ServiceClient*>* activate_srv_clients_;
        /* Robot deactivation service clients */
        std::vector<ros::ServiceClient*>* deactivate_srv_clients_;
        /* Robot toggle activate service clients */
        std::vector<ros::ServiceClient*>* toglActivate_srv_clients_;
        /* Robot reset service clients */
        std::vector<ros::ServiceClient*>* reset_srv_clients_;

        std_srvs::Empty srv_;

        /*===========================
         * Callbacks
         *===========================*/
        /*
         * Callback class method for robot activation service
         */
        bool activateCallback(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response);

        /*
         * Callback class method for robot deactivation service
         */
        bool deactivateCallback(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response);

        /*
         * Callback class method for robot toggle activate service
         */
        bool toglActivateCallback(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response);

        /*
         * Callback class method for robot reset service
         */
        bool resetCallback(std_srvs::Empty::Request& request, std_srvs::Empty::Response& response);

        /*===========================
         * Utilities
         *===========================*/
        /*
         * Create services
         */
        void createServices(std::string nsPrefix, int qty);

        /*
         * Call individual services in vector corresponding to pointer
         */
        void callServiceVector(std::vector<ros::ServiceClient*>* srv_clients);

        /*
         * Deallocate
         */
        void clearServiceVector(std::vector<ros::ServiceClient*>* srvs);
};

#endif  // ELIKOS_ROOMBA_SERVICE_REDIRECT_H