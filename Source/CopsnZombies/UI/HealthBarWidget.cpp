// Personal Project made by Marc Meijering, if code is taken from others it will be specified in the same file.


#include "HealthBarWidget.h"

#include "Components/ProgressBar.h"

void UHealthBarWidget::SetHealthBar(const float Value)
{
    HealthBar->SetPercent(Value);
}
