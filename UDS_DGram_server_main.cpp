#include <iostream>
#include <string>
#include <tools/unix_domain_socket/UDSDGramServer.h>
#include <savari/sv2x_facif_msg.h>

using namespace std;

#define BUFSIZE 62000

#define NAME(X) #X

// TODO : how to use print_arg replace "sv2x_msg.u.rvbsm.latitude"
string print_arg = "";

#if 1 // print all
#define OUT(X)  { \
                    string xname = NAME(X); \
                    if (sizeof(X) == 1) \
                    {\
                        printf("%s : %d \n", xname.c_str(), X); \
                    } else { \
                        cout << xname << ":" << X << endl; \
                    }\
                }
#else // print single
#define OUT(X) { \
                    string xname = NAME(X); \
                    if (xname == print_arg) { \
                        if (sizeof(X) == 1) \
                        {\
                            printf("%s : %d \n", xname.c_str(), X); \
                        } else { \
                            cout << xname << ":" << X << endl; \
                        }\
                    } \
                }

#endif

void ShowRVSv2xMsg(const sv2x_facif_msg_t &sv2x_msg)
{
    OUT(sv2x_msg.msg_type);
    OUT(sv2x_msg.length);
    OUT(sv2x_msg.u.rvbsm.bit_mask);
    OUT(sv2x_msg.u.rvbsm.msg_count);
    OUT(sv2x_msg.u.rvbsm.temp_id);
    OUT(sv2x_msg.u.rvbsm.sec_mark);
    OUT(sv2x_msg.u.rvbsm.latitude);
    OUT(sv2x_msg.u.rvbsm.longitude);
    OUT(sv2x_msg.u.rvbsm.elevation);
    OUT(sv2x_msg.u.rvbsm.plat_no);
    OUT(sv2x_msg.u.rvbsm.positional_accuracy.semi_major_axis_accuracy);
    OUT(sv2x_msg.u.rvbsm.positional_accuracy.semi_minor_axis_accuracy);
    OUT(sv2x_msg.u.rvbsm.positional_accuracy.semi_major_orien_accuracy);
    OUT(sv2x_msg.u.rvbsm.transmission_state);
    OUT(sv2x_msg.u.rvbsm.speed);
    OUT(sv2x_msg.u.rvbsm.heading);
    OUT(sv2x_msg.u.rvbsm.angle);
    

    // all ways accelaration.
    OUT(sv2x_msg.u.rvbsm.lat_accel);
    OUT(sv2x_msg.u.rvbsm.lon_accel);
    OUT(sv2x_msg.u.rvbsm.vert_accel);
    OUT(sv2x_msg.u.rvbsm.yawrate);

    // brake system status
    OUT(sv2x_msg.u.rvbsm.brake_system_status.brake_padel);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.wheel_brake);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.traction_control_status);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.antilock_brake_status);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.stability_control_status);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.brake_boost);
    OUT(sv2x_msg.u.rvbsm.brake_system_status.auxiliary_brake_status);

    // object size
    OUT(sv2x_msg.u.rvbsm.width);
    OUT(sv2x_msg.u.rvbsm.length);
    OUT(sv2x_msg.u.rvbsm.height);

    // safety vehicle extension
    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.events);
    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_count);
    for (int i = 0; i < sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_count; i++)
    {
        OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_points[i].lat_Offset);
        OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_points[i].lon_Offset);
        OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_points[i].elev_Offset);
        OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.ph_points[i].time_Offset);

    }

    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.path_prediction.radius);
    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.path_prediction.confidence);
    OUT(sv2x_msg.u.rvbsm.safety_vehicle_extension.lights);

    // special vehicle extension
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.vehicle_alerts.ssp_index);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.vehicle_alerts.siren_in_use);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.vehicle_alerts.light_bar_in_use);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.vehicle_alerts.multi_vehicle_response);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.event_description.bit_mask);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.event_description.type_event);
    OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.event_description.number_of_itis_codes);
    //OUT(sv2x_msg.u.rvbsm.special_vehicle_extension.event_description.description[]);
   
   // supplemental vehicle extesion
    OUT(sv2x_msg.u.rvbsm.supplemental_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.rvbsm.supplemental_vehicle_extension.class_details.bit_mask);
    OUT(sv2x_msg.u.rvbsm.supplemental_vehicle_extension.class_details.basic_veh_class_keytype);
    OUT(sv2x_msg.u.rvbsm.supplemental_vehicle_extension.class_details.basic_veh_role);
    OUT(sv2x_msg.u.rvbsm.supplemental_vehicle_extension.class_details.hpms_type);
 
}

void ShowHVSv2xMsg(const sv2x_facif_msg_t &sv2x_msg)
{
    OUT(sv2x_msg.msg_type);
    OUT(sv2x_msg.length);
    OUT(sv2x_msg.u.hvbsm.bit_mask);
    OUT(sv2x_msg.u.hvbsm.msg_count);
    OUT(sv2x_msg.u.hvbsm.temp_id);
    OUT(sv2x_msg.u.hvbsm.sec_mark);
    OUT(sv2x_msg.u.hvbsm.latitude);
    OUT(sv2x_msg.u.hvbsm.longitude);
    OUT(sv2x_msg.u.hvbsm.elevation);
    OUT(sv2x_msg.u.hvbsm.plat_no);
    OUT(sv2x_msg.u.hvbsm.positional_accuracy.semi_major_axis_accuracy);
    OUT(sv2x_msg.u.hvbsm.positional_accuracy.semi_minor_axis_accuracy);
    OUT(sv2x_msg.u.hvbsm.positional_accuracy.semi_major_orien_accuracy);
    OUT(sv2x_msg.u.hvbsm.transmission_state);
    OUT(sv2x_msg.u.hvbsm.speed);
    OUT(sv2x_msg.u.hvbsm.heading);
    // OUT(sv2x_msg.u.hvbsm.angle);
    printf("sv2x_msg.u.hvbsm.angle : %d\n", sv2x_msg.u.hvbsm.angle);

    // all ways accelaration.
    OUT(sv2x_msg.u.hvbsm.lat_accel);
    OUT(sv2x_msg.u.hvbsm.lon_accel);
    OUT(sv2x_msg.u.hvbsm.vert_accel);
    OUT(sv2x_msg.u.hvbsm.yawrate);

    // brake system status
    OUT(sv2x_msg.u.hvbsm.brake_system_status.brake_padel);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.wheel_brake);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.traction_control_status);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.antilock_brake_status);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.stability_control_status);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.brake_boost);
    OUT(sv2x_msg.u.hvbsm.brake_system_status.auxiliary_brake_status);

    // object size
    OUT(sv2x_msg.u.hvbsm.width);
    OUT(sv2x_msg.u.hvbsm.length);
    OUT(sv2x_msg.u.hvbsm.height);

    // safety vehicle extension
    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.events);
    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_count);
    for (int i = 0; i < sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_count; i++)
    {
        OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_points[i].lat_Offset);
        OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_points[i].lon_Offset);
        OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_points[i].elev_Offset);
        OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.ph_points[i].time_Offset);

    }

    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.path_prediction.radius);
    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.path_prediction.confidence);
    OUT(sv2x_msg.u.hvbsm.safety_vehicle_extension.lights);

    // special vehicle extension
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.vehicle_alerts.ssp_index);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.vehicle_alerts.siren_in_use);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.vehicle_alerts.light_bar_in_use);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.vehicle_alerts.multi_vehicle_response);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.event_description.bit_mask);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.event_description.type_event);
    OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.event_description.number_of_itis_codes);
    //OUT(sv2x_msg.u.hvbsm.special_vehicle_extension.event_description.description[]);
   
   // supplemental vehicle extesion
    OUT(sv2x_msg.u.hvbsm.supplemental_vehicle_extension.bit_mask);
    OUT(sv2x_msg.u.hvbsm.supplemental_vehicle_extension.class_details.bit_mask);
    OUT(sv2x_msg.u.hvbsm.supplemental_vehicle_extension.class_details.basic_veh_class_keytype);
    OUT(sv2x_msg.u.hvbsm.supplemental_vehicle_extension.class_details.basic_veh_role);
    OUT(sv2x_msg.u.hvbsm.supplemental_vehicle_extension.class_details.hpms_type);
 
}
int main(int argc, char* argv[])
{
    UDSDGramServer server;
    if (!server.Init("uds_dgram.socket"))
    {
        cerr << " server init error !" << endl;
        return -1;
    }

    if (argc == 2)
    {
        print_arg = argv[1];
        cout << "print_arg = " << print_arg << endl;
    }

    char buf[BUFSIZE] = {'\0'};
    int size = 0;

    sv2x_facif_msg_t sv2x_msg;

    while (1)
    {
        size = server.Receive(buf, BUFSIZE);
        if (size < 0)
        {
            cerr << "recvfrom error" << endl;
            continue;
        }
        else if (size == 0)
        {
            cout << "EOF" << endl;
        }

        static bool rv_has_come = false;
        static bool hv_has_come = false;

        if (!rv_has_come || !hv_has_come) {
            memset(&sv2x_msg, 0x00, sizeof(sv2x_msg));
            memcpy(&sv2x_msg, buf, sizeof(sv2x_msg));
            // printf("recv: %s \n", buf);
            // printf("recv_size: %u \n", size);
            if (!rv_has_come && sv2x_msg.msg_type == SV2X_FACIF_MSG_TYPE_RV_BSM)
            {
                cout << "------------- Remote Vehicle info ----------------" << endl;
                ShowRVSv2xMsg(sv2x_msg);
                rv_has_come = true;
            }
            else if (!hv_has_come && sv2x_msg.msg_type == SV2X_FACIF_MSG_TYPE_HV_BSM)
            {
                cout << "------------- Host Vehicle info ----------------" << endl;
                ShowHVSv2xMsg(sv2x_msg);
                hv_has_come = true;

            }
        }
    }

    return 0;
}
