/*
 * Copyright 2003,2004 The Apache Software Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _LOG4CXX_HELPERS_DATE_FORMAT_H
#define _LOG4CXX_HELPERS_DATE_FORMAT_H

#include <log4cxx/helpers/timezone.h>

namespace log4cxx
{
        namespace helpers
        {
                class DateFormat;
                typedef helpers::ObjectPtrT<DateFormat> DateFormatPtr;

                /**
                *  DateFormat is an abstract class for date/time formatting
                * patterned after java.text.DateFormat.
                */
                class LOG4CXX_EXPORT DateFormat : public ObjectImpl {
                   public:
                   DECLARE_ABSTRACT_LOG4CXX_OBJECT(DateFormat)
                   BEGIN_LOG4CXX_CAST_MAP()
                           LOG4CXX_CAST_ENTRY(DateFormat)
                   END_LOG4CXX_CAST_MAP()

                  /**
                  *  Destructor
                  */
                   virtual ~DateFormat();

                   /**
                   * Formats an apr_time_t into a date/time string.
                   * @param s string to which the date/time string is appended.
                   * @param date date to be formatted.
                   * @param p memory pool used during formatting.
                   */
                   virtual void format(std::string &s, apr_time_t date, apr_pool_t* p) const = 0;

                   /**
                   * Sets the time zone.
                   * @param zone the given new time zone.
                   */
                   virtual void setTimeZone(const TimeZonePtr& zone);

                   /**
                   * Format an integer consistent with the format method.
                   * @param s string to which the numeric string is appended.
                   * @param n integer value.
                   * @param p memory pool used during formatting.
                   * @remarks This method is used by CachedDateFormat to
                   * format the milliseconds.
                   */
                   virtual void numberFormat(std::string& s, int n, apr_pool_t* p) const;


                   protected:
                   /**
                   * Constructor.
                   */
                   DateFormat();

                   private:
                   /**
                   *  Copy constructor definition to prevent copying.
                   */
                   DateFormat(const DateFormat&);
                   /**
                   *  Assignment definition to prevent assignment.
                   */
                   DateFormat& operator=(const DateFormat&);
                };



        }  // namespace helpers
}; // namespace log4cxx

#endif //_LOG4CXX_HELPERS_DATE_FORMAT_H
