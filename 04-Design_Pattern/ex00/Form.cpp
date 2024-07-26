#include <Form.hpp>

ostream&	operator<<(ostream& os, const Form& form){
	if (form._formType == FormType::CourseFinished)
		os << "CourseFinished";
	else if (form._formType == FormType::NeedMoreClassRoom)
		os << "NeedMoreClassRoom";
	else if (form._formType == FormType::NeedCourseCreation)
		os << "NeedCourseCreation";
	else if (form._formType == FormType::SubscriptionToCourse)
		os << "SubscriptionToCourse";
	return (os);
}
