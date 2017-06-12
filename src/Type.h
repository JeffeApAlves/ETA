#ifndef TYPE_H
#define TYPE_H

#define	MAX_TEXT_LEN	20

/**Possiveis status para o SW*/
typedef enum 	{	APP_CLOSED=0,
					APP_CLOSING,
					APP_RUNNING,
					APP_REQUEST_CLOSE,					
					APP_STARTING,
					APP_STARTED,
					APP_RUNNING_SIMULATION,
					APP_MEASUREMENT
				} TStatusApp;

/**Interfaces de fonte dados disponiveis*/					
typedef enum	{INTERFACE_RBPI3,
				INTERFACE_SIM_RANDOM,
				INTERFACE_SIM_INCR,
				} TInterface;

/**Possiveis status para os Sensores*/
typedef enum 	{OFF,
				ON,
				ERROR
				} TSensorStatus;

/**Possiveis status para o item do menu*/
typedef enum	{
					DISABLE,					/**indica item da lista disabilitado */
					ENABLED,					/**indica item da lista habilitado */
					SELECTED					/**indica item da lista selecionado */
				} TStatusItem ;

typedef struct	{	

					float Min,Max;
				}TScale;
				
/**Tipos de menu*/
typedef enum	{VERTICAL,HORIZONTAL} TStyle;

/**Volume*/
typedef float	TVolume;

/**Vazao*/
typedef float	TFlow;

/**Doze*/
typedef float	TDose;

/**Texto*/
typedef char	TText;

/**Percentual*/
typedef int		TPercentual;

#endif

